//
//  main.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include <iostream>
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <libxml/schemasInternals.h>
#include <libxml/xmlschemastypes.h>
#include <sys/stat.h>
#include <map>

#include "NoPLc.h"
#include "NoPLValues.h"
#include "NoPLStandardFunctions.h"
#include "NoPLRuntime.h"

#include "NoPLSchemaNode.h"
#include "SchemaAbstractions.h"

#pragma mark - NoPL callback prototypes

void processNoPLFeedback(const char* string, NoPL_StringFeedbackType type);
NoPL_FunctionValue evaluateNoPLFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
NoPL_FunctionValue evaluateNoPLSubscript(void* calledOnObject, NoPL_FunctionValue index);

#pragma mark - misc

NoPLSchemaNode* schemaData;
SchemaAbstractions* abstractions;
xmlDocPtr xmlDocument;
FILE* outputFile = NULL;
std::string currentFilePath;
std::string basePath;
std::map<std::string, std::string> typeMappings;

std::string absolutePath(char* anyPath)
{
	//check if the path is relative
	std::string path = anyPath;
	if(path[0] != '/')
		path = basePath+path;
	return path;
}

bool attemptReplaceSuffix(std::string* outStr, const std::string oldSuffix, const std::string newSuffix)
{
	std::string input = *outStr;
	//make sure that this could even be possible
	if (input.length() >= oldSuffix.length())
	{
		//check if this is actually the suffix of the string
        bool endingMatches = (0 == input.compare(input.length() - oldSuffix.length(), oldSuffix.length(), oldSuffix));
		if(endingMatches)
		{
			//replace the suffix
			
			*outStr = input.substr(0, input.length() - oldSuffix.length()) + newSuffix;
			return true;
		}
    }
	return false;
}

#pragma mark - Schema validation

int isSchemaValid(xmlDocPtr schema_doc)
{
    xmlSchemaParserCtxtPtr parserCtx = xmlSchemaNewDocParserCtxt(schema_doc);
    if(!parserCtx)
        return 0;
    xmlSchemaPtr schema = xmlSchemaParse(parserCtx);
	
	int isValid = 0;
	if(schema)
	{
		isValid = 1;
		xmlSchemaFree(schema);
	}
	xmlSchemaFreeParserCtxt(parserCtx);
	return isValid;
}

#pragma mark - NoPL

int runScriptAtPath(const char* filePath)
{
	//compile the nopl script
	NoPL_CompileContext noplContext = newNoPL_CompileContext();
	NoPL_CompileOptions options = NoPL_CompileOptions();
	options.optimizeForRuntime = 0;
	compileContextWithFilePath(filePath, &options, &noplContext);
	
	//check for errors
	if(noplContext.errDescriptions)
	{
		printf("NoPL script failed to compile with errors:\n%s", noplContext.errDescriptions);
		freeNoPL_CompileContext(&noplContext);
		return 0;
	}
	
	//set up the callback functions
	NoPL_Callbacks callbacks = NoPL_Callbacks();
	callbacks.evaluateFunction = evaluateNoPLFunction;
	callbacks.subscript = evaluateNoPLSubscript;
	callbacks.stringFeedback = processNoPLFeedback;
	
	//run the script
	runScript((NoPL_Instruction*)noplContext.compiledData, (unsigned int)noplContext.dataLength, &callbacks);
	
	//free the context
	freeNoPL_CompileContext(&noplContext);
	return 1;
}

void processNoPLFeedback(const char* string, NoPL_StringFeedbackType type)
{
	switch(type)
	{
		case NoPL_StringFeedbackType_PrintStatement:
		case NoPL_StringFeedbackType_Metadata:
			
			if(outputFile)
				fputs(string, outputFile);
			
			break;
		case NoPL_StringFeedbackType_RuntimeError:
			printf("SCRIPT ERROR: %s\n", string);
			break;
		default:
			break;
	}
}

NoPL_FunctionValue evaluateNoPLFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//check if we're calling a global
	if(!calledOnObject)
	{
		//calling a global, we're not accepting any arguments
		if(argc == 0)
		{
			if(!strcmp(functionName, "schema") && schemaData)
			{
				retVal.pointerValue = schemaData;
				retVal.type = NoPL_DataType_Pointer;
			}
			else if(!strcmp(functionName, "abstractions"))
			{
				retVal.pointerValue = abstractions;
				retVal.type = NoPL_DataType_Pointer;
			}
		}
		else if(argc == 1 && argv[0].type == NoPL_DataType_String)
		{
			//functions that take one string argument
			if(!strcmp(functionName, "outputToFile"))
			{
				//close the old file if there is one
				if(outputFile)
					fclose(outputFile);
				
				//check if the path is relative
				std::string path = absolutePath(argv[0].stringValue);
				
				//loop over the path to create any directories that this file will need
				char directoryChecks[path.length()+1];
				strcpy(directoryChecks, path.c_str());
				while(true)
				{
					//find the last directory delimiter
					char* lastSlash = strrchr(directoryChecks, '/');
					if(!lastSlash)
						break;
					
					//shorten the path to only go up to this directory
					*lastSlash = '\0';
					if(strlen(directoryChecks) < 2)
						break;
					
					//TODO: mkdir and stat are for unix, what about other platforms?
					struct stat st;
					int directoryExists = !stat(directoryChecks, &st);
					if(!directoryExists)
						mkdir(directoryChecks, 0777);
				}
				
				outputFile = fopen(path.c_str(), "w");
				
				retVal.type = NoPL_DataType_Void;
			}
			else if(!strcmp(functionName, "fileExists"))
			{
				//get the absolute path
				std::string path = absolutePath(argv[0].stringValue);
				
				//check if this file exists
				FILE* file = fopen(path.c_str(), "r");
				retVal.booleanValue = (file != NULL);
				retVal.type = NoPL_DataType_Boolean;
				
				//cleanup
				if(file)
					fclose(file);
			}
			else if(!strcmp(functionName, "console") || !strcmp(functionName, "c"))
			{
				//output to the command line
				printf("%s\n", argv[0].stringValue);
				retVal.type = NoPL_DataType_Void;
			}
			else if(!strcmp(functionName, "runScript"))
			{
				//return a boolean for compile success or failure
				retVal.booleanValue = runScriptAtPath(absolutePath(argv[0].stringValue).c_str());
				retVal.type = NoPL_DataType_Boolean;
			}
			else if(!strcmp(functionName, "valueForKey"))
			{
				//check if the map has the key
				const char* mappingResult;
				if(typeMappings.find(argv[0].stringValue) != typeMappings.end())
				{
					//this key was found, use the mapped value
					mappingResult = typeMappings[argv[0].stringValue].c_str();
				}
				else
				{
					//key was not found, use the original value
					mappingResult = argv[0].stringValue;
				}
				
				NoPL_assignString(mappingResult, retVal);
			}
			else if(!strcmp(functionName, "pluralize"))
			{
				//this is a convenience function for naming lists of stuff
				//(pluralizing everything correctly is surprisingly hard in english)
				std::string listName = argv[0].stringValue;
				
				//attempt a list of pretty reliable english language singular->plural substitutions
				bool didReplace = attemptReplaceSuffix(&listName, "us", "i");//ex: cactus -> cacti
				if(!didReplace)
					didReplace = attemptReplaceSuffix(&listName, "is", "es");//ex: crisis -> crises
				if(!didReplace)
					didReplace = attemptReplaceSuffix(&listName, "ix", "ices");//ex: matrix -> matrices
//				if(!didReplace)
//					didReplace = attemptReplaceSuffix(&listName, "um", "a");//ex: datum -> data
				if(!didReplace)
					didReplace = attemptReplaceSuffix(&listName, "y", "ies");//ex: tally -> tallies
				
				//if none of these fancy things work, just add 's'
				if(!didReplace)
					listName += "s";
				
				const char* cVal = (const char*)listName.c_str();
				NoPL_assignString(cVal, retVal);
			}
		}
		else if(argc == 2 &&
				argv[0].type == NoPL_DataType_String &&
				argv[1].type == NoPL_DataType_String &&
				!strcmp(functionName, "setKeyAndValue"))
		{
			//set the mapping for this type
			typeMappings[argv[0].stringValue] = argv[1].stringValue;
		}
	}
	else
	{
		//we're attempting to get at a specific object
		NoPLInterface* noplObject = (NoPLInterface*)calledOnObject;
		retVal = noplObject->evaluateFunction(functionName, argv, argc);
	}
	
	if(retVal.type == NoPL_DataType_Uninitialized)
	{
		//try the standard functions
		retVal = nopl_standardFunctions(calledOnObject, functionName, argv, argc);
	}
	
	if(retVal.type == NoPL_DataType_Uninitialized)
	{
		//we have failed to produce anything useful here, but we should never return 'Uninitialized'
		retVal.type = NoPL_DataType_Pointer;
		retVal.pointerValue = NULL;
	}
	
	return retVal;
}

NoPL_FunctionValue evaluateNoPLSubscript(void* calledOnObject, NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	if(calledOnObject)
	{
		NoPLInterface* noplObject = (NoPLInterface*)calledOnObject;
		retVal = noplObject->evaluateSubscript(index);
	}
	
	return retVal;
}

#pragma mark - main

void cleanup()
{
	if(outputFile)
		fclose(outputFile);
	
	if(schemaData)
	{
		delete schemaData;
		schemaData = NULL;
	}
	if(abstractions)
	{
		delete abstractions;
		abstractions = NULL;
	}
	if(xmlDocument)
		xmlFreeDoc(xmlDocument);
}

int main(int argc, const char * argv[])
{
	if(argc != 3)
	{
		printf("NoPLGenerator requires 2 arguments: path to XML Schema file and path to NoPL script file");
		return -1;
	}
	
	//get the args
	const char* schemaFilePath = argv[1];
	const char* scriptFilePath = argv[2];
	
	//get the root path
	basePath = scriptFilePath;
	size_t index = basePath.find_last_of('/');
	basePath = basePath.substr(0, index+1);
	
	//check libxml2 version
	LIBXML_TEST_VERSION
	
	//load the schema document from file
	xmlDocument = xmlReadFile(schemaFilePath, NULL, XML_PARSE_XINCLUDE|XML_PARSE_NONET|XML_PARSE_NSCLEAN);//TODO: what are the settings we want here?
	if(!xmlDocument)
	{
		printf("Could not successfully load the XML file.");
		cleanup();
		return -1;
	}
	
	//make sure this doc is a valid schema file
	if(!isSchemaValid(xmlDocument))
	{
		printf("XML schema file was not valid.");
		cleanup();
		return -1;
	}
	
	//we have valid schema XML, build that into a series of model objects
	schemaData = new NoPLSchemaNode(xmlDocument->children);
	abstractions = new SchemaAbstractions(schemaData);
	
	int success = runScriptAtPath(scriptFilePath);
	
	//free the objects that we've made
	cleanup();
	
    return success ? 0 : -1;
}
