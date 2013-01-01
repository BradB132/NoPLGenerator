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

#pragma mark - Schema

xmlSchemaPtr loadSchemaAtPath(const char* schemaPath)
{
	//load the schema document from file
	xmlDocPtr xmlDoc = xmlReadFile(schemaPath, NULL, XML_PARSE_XINCLUDE|XML_PARSE_NONET);//TODO: what are the settings we want here?
	if(!xmlDoc)
		return NULL;
	
	//attempt to create a parser
	xmlSchemaParserCtxtPtr parser = xmlSchemaNewDocParserCtxt(xmlDoc);
	if(!parser)
	{
		xmlFreeDoc(xmlDoc);
		return NULL;
	}
	
	//attempt to parse the document as a schema
	xmlSchemaPtr schemaDoc = xmlSchemaParse(parser);
	
	//free the objects that were used to load
	xmlSchemaFreeParserCtxt(parser);
	xmlFreeDoc(xmlDoc);

	return schemaDoc;
}

void evaluateType(void * payload, void * data, xmlChar * name)
{
	printf("Type: %s\n", name);
}

void evaluateAttribute(void * payload, void * data, xmlChar * name)
{
	printf("Attribute: %s\n", name);
}

void evaluateAttributeGroup(void * payload, void * data, xmlChar * name)
{
	printf("Attribute Group: %s\n", name);
}

void evaluateElement(void * payload, void * data, xmlChar * name)
{
	printf("Element: %s\n", name);
//	xmlNodePtr node = (xmlNodePtr)payload;//TODO: is this a xmlNodePointer?
	
}

void evaluateNotation(void * payload, void * data, xmlChar * name)
{
	printf("Notation: %s\n", name);
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
	
	//load the schema
	xmlSchemaPtr schema = loadSchemaAtPath(schemaFilePath);
	if(schema->typeDecl)
		xmlHashScan(schema->typeDecl, evaluateType, NULL);
	if(schema->attrDecl)
		xmlHashScan(schema->attrDecl, evaluateAttribute, NULL);
	if(schema->attrgrpDecl)
		xmlHashScan(schema->attrgrpDecl, evaluateAttributeGroup, NULL);
	if(schema->elemDecl)
		xmlHashScan(schema->elemDecl, evaluateElement, NULL);
	if(schema->notaDecl)
		xmlHashScan(schema->notaDecl, evaluateNotation, NULL);
	
    return 0;
}
