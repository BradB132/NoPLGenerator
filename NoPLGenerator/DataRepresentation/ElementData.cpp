//
//  ElementData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "ElementData.h"

#pragma mark - Constructor / Destructor

ElementData::ElementData(xmlNodePtr xmlNode):
annotation(NULL),
simpleType(NULL),
complexType(NULL),
SchemaBaseData(xmlNode)
{
	//check all of the children of this node
	xmlNodePtr child = xmlNode->children;
	while(child)
	{
		if(!strcmp((char*)child->name, "annotation"))
			annotation = new AnnotationData(child);
		else if(!strcmp((char*)child->name, "simpleType"))
			simpleType = new SimpleTypeData(child);
		else if(!strcmp((char*)child->name, "complexType"))
			complexType = new ComplexTypeData(child);
		
		//iterate to the next child
		child = child->next;
	}
}

ElementData::~ElementData()
{
	
}

#pragma mark - Lazy accessors

AnnotationData* ElementData::getAnnotation()
{
	return annotation;
}

SimpleTypeData* ElementData::getSimpleType()
{
	return simpleType;
}

ComplexTypeData* ElementData::getComplexType()
{
	return complexType;
}

#pragma mark - NoPL

NoPL_FunctionValue ElementData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//we're not accepting any arguments
	if(argc == 0)
	{
		if(!strcmp(functionName, "annotation"))
		{
			retVal.pointerValue = annotation;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "simpleType"))
		{
			retVal.pointerValue = simpleType;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "complexType"))
		{
			retVal.pointerValue = complexType;
			retVal.type = NoPL_DataType_Pointer;
		}
	}
	
	//return the result if we found one
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return SchemaBaseData::evaluateFunction(functionName, argv, argc);
}

