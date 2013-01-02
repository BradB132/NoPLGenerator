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

#pragma mark - Schema

xmlSchemaPtr loadSchemaAtPath(const char* schemaPath)
{
	//load the schema document from file
	xmlDocPtr xmlDoc = xmlReadFile(schemaPath, NULL, XML_PARSE_XINCLUDE|XML_PARSE_NONET|XML_PARSE_NSCLEAN);//TODO: what are the settings we want here?
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

void evaluateElement(void * payload, void * data, xmlChar * name)
{
	xmlSchemaElementPtr element = (xmlSchemaElementPtr)payload;
	xmlNodePtr node = element->node;
	NoPLInterface* parent = (NoPLInterface*)data;
	
	switch (element->type)
	{
		case XML_SCHEMA_TYPE_ELEMENT:
		{
			printf("ELEMENT: %s\n", name);
			
			const xmlChar * type = xmlGetProp(node, (xmlChar*)"type");
			if(type)
			{
				
			}
			else
			{
				
			}
		}
			break;
		case XML_SCHEMA_TYPE_ATTRIBUTE:
		{
			printf("ATTRIBUTE: %s\n", name);
		}
			break;
		case XML_SCHEMA_TYPE_ATTRIBUTEGROUP:
		{
			printf("ATTRIBUTE GROUP: %s\n", name);
		}
			break;
		case XML_SCHEMA_TYPE_GROUP:
		{
			printf("GROUP: %s\n", name);
		}
			break;
		case XML_SCHEMA_TYPE_NOTATION:
		{
			printf("NOTATION: %s\n", name);
		}
			break;
		case XML_SCHEMA_TYPE_SIMPLE:
		{
			printf("SIMPLE TYPE: %s\n", name);
		}
			break;
		case XML_SCHEMA_TYPE_COMPLEX:
		{
			printf("COMPLEX TYPE: %s\n", name);
		}
			break;
		default:
			break;
	}
}

SchemaData* parseSchemaData(xmlSchemaPtr schema)
{
	SchemaData* returnData = new SchemaData();
	
	if(schema->typeDecl)
		xmlHashScan(schema->typeDecl, evaluateElement, returnData);
	if(schema->attrDecl)
		xmlHashScan(schema->attrDecl, evaluateElement, returnData);
	if(schema->attrgrpDecl)
		xmlHashScan(schema->attrgrpDecl, evaluateElement, returnData);
	if(schema->elemDecl)
		xmlHashScan(schema->elemDecl, evaluateElement, returnData);
	if(schema->notaDecl)
		xmlHashScan(schema->notaDecl, evaluateElement, returnData);
	if(schema->groupDecl)
		xmlHashScan(schema->groupDecl, evaluateElement, returnData);
//	if(schema->idcDef)
//		xmlHashScan(schema->idcDef, evaluateElement, returnData);
//	if(schema->schemasImports)
//		xmlHashScan(schema->schemasImports, evaluateElement, returnData);
	
	return returnData;
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
	LIBXML_TEST_VERSION
	xmlSchemaPtr schema = loadSchemaAtPath(schemaFilePath);
	if(!schema)
	{
		printf("Could not successfully load the schema file.");
		return -1;
	}
	
	SchemaData* schemaData = parseSchemaData(schema);
	
    return 0;
}
