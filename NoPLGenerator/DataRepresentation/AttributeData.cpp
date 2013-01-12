//
//  AttributeData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "AttributeData.h"

#pragma mark - Constructor / Destructor

AttributeData::AttributeData(xmlNodePtr xmlNode):
annotation(NULL),
simpleType(NULL),
SchemaBaseData(xmlNode)
{
	
}

AttributeData::~AttributeData()
{
	if(annotation)
	{
		delete annotation;
		annotation = NULL;
	}
	if(simpleType)
	{
		delete simpleType;
		simpleType = NULL;
	}
}

#pragma mark - NoPL

NoPL_FunctionValue AttributeData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue AttributeData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}