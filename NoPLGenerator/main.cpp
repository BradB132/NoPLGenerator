//
//  main.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include <iostream>
#include "SchemaData.h"
#include "NoPLc.h"
#include "NoPLRuntime.h"

#include <libxml/parser.h>
#include <libxml/xmlschemas.h>
#include <libxml/schemasInternals.h>
#include <libxml/xmlschemastypes.h>

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

//TODO: nopl callbacks

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
	
	//we have a valid schema file, parse it
	SchemaData* schemaData = new SchemaData(xmlDoc->children);
	
	
	xmlFreeDoc(xmlDoc);
	
    return 0;
}
