//
//  SimpleTypeData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "SimpleTypeData.h"

SimpleTypeData::SimpleTypeData(xmlNodePtr xmlNode):
annotation(NULL),
restriction(NULL),
_union(NULL),
SchemaBaseData(xmlNode)
{
	
}

SimpleTypeData::~SimpleTypeData()
{
	
}

NoPL_FunctionValue SimpleTypeData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue SimpleTypeData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}