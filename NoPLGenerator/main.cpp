//
//  main.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include <iostream>
#include "SchemaData.h"

#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <libxml/schemasInternals.h>
#include <libxml/xmlschemastypes.h>

#include "NoPLc.h"
#include "NoPLValues.h"
#include "NoPLStandardFunctions.h"
#include "NoPLRuntime.h"

#pragma mark - Declared variables

SchemaData* schemaData;

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
	printf("NoPL: %s", string);
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
			else if(!strcmp(functionName, "classes"))
			{
				//TODO: class abstractions
			}
		}
	}
	else
	{
		//we're attempting to get at a specific object
		SchemaBaseData* base = (SchemaBaseData*)calledOnObject;
		retVal = base->evaluateFunction(functionName, argv, argc);
	}
	
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return nopl_standardFunctions(calledOnObject, functionName, argv, argc);
}

NoPL_FunctionValue evaluateNoPLSubscript(void* calledOnObject, NoPL_FunctionValue index)
{
	NoPL_FunctionValue val;
	val.type = NoPL_DataType_Uninitialized;
	return val;
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
	schemaData = new SchemaData(xmlDoc->children);
	
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
	delete schemaData;
	schemaData = NULL;
	xmlFreeDoc(xmlDoc);
	
    return 0;
}
