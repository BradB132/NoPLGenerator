//
//  ComplexTypeData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "ComplexTypeData.h"

ComplexTypeData::ComplexTypeData(xmlNodePtr xmlNode):
annotation(NULL),
attributes(NULL),
attributeGroups(NULL),
SchemaBaseData(xmlNode)
{
	
}

ComplexTypeData::~ComplexTypeData()
{
	
}

NoPL_FunctionValue ComplexTypeData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue ComplexTypeData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}