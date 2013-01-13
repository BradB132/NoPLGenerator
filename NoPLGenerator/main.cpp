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

#include "NoPLc.h"
#include "NoPLValues.h"
#include "NoPLStandardFunctions.h"
#include "NoPLRuntime.h"

#include "NoPLSchemaNode.h"
#include "SchemaAbstractions.h"

#pragma mark - Declared variables

NoPLSchemaNode* schemaData;
SchemaAbstractions* abstractions;

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

#pragma mark - NoPL callbacks

void processNoPLFeedback(const char* string, NoPL_StringFeedbackType type)
{
	switch(type)
	{
		case NoPL_StringFeedbackType_PrintStatement:
			printf("%s\n", string);
			break;
		case NoPL_StringFeedbackType_Metadata:
			//TODO: we're getting some template data, print this to file
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
	
	//check libxml2 version
	LIBXML_TEST_VERSION
	
	//load the schema document from file
	xmlDocPtr xmlDoc = xmlReadFile(schemaFilePath, NULL, XML_PARSE_XINCLUDE|XML_PARSE_NONET|XML_PARSE_NSCLEAN);//TODO: what are the settings we want here?
	if(!xmlDoc)
	{
		printf("Could not successfully load the XML file.");
		return -1;
	}
	
	//make sure this doc is a valid schema file
	if(!isSchemaValid(xmlDoc))
	{
		printf("XML schema file was not valid.");
		return -1;
	}
	
	//we have valid schema XML, build that into a series of model objects
	schemaData = new NoPLSchemaNode(xmlDoc->children);
	abstractions = new SchemaAbstractions(schemaData);
	
	//compile the nopl script
	NoPL_CompileContext noplContext = newNoPL_CompileContext();
	NoPL_CompileOptions options = NoPL_CompileOptions();
	options.optimizeForRuntime = 0;
	compileContextWithFilePath(scriptFilePath, &options, &noplContext);
	
	//check for errors
	if(noplContext.errDescriptions)
	{
		printf("NoPL script failed to compile with errors:\n%s", noplContext.errDescriptions);
		return -1;
	}
	
	//set up the callback functions
	NoPL_Callbacks callbacks = NoPL_Callbacks();
	callbacks.evaluateFunction = evaluateNoPLFunction;
	callbacks.subscript = evaluateNoPLSubscript;
	callbacks.stringFeedback = processNoPLFeedback;
	
	//run the script
	runScript((NoPL_Instruction*)noplContext.compiledData, (unsigned int)noplContext.dataLength, &callbacks);
	
	//TODO: better job of cleanup if we exit early
	//free the objects that we've made
	freeNoPL_CompileContext(&noplContext);
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
	xmlFreeDoc(xmlDoc);
	
    return 0;
}
