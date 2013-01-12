//
//  AttributeGroupData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "AttributeGroupData.h"

AttributeGroupData::AttributeGroupData(xmlNodePtr xmlNode):
annotation(NULL),
attributes(NULL),
attributeGroups(NULL),
SchemaBaseData(xmlNode)
{
	
}

AttributeGroupData::~AttributeGroupData()
{
	
}

NoPL_FunctionValue AttributeGroupData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue AttributeGroupData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}