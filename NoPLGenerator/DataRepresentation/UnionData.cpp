//
//  UnionData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "UnionData.h"

UnionData::UnionData(xmlNodePtr xmlNode):
annotation(NULL),
simpleTypes(NULL),
SchemaBaseData(xmlNode)
{
	
}

UnionData::~UnionData()
{
	
}

NoPL_FunctionValue UnionData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue UnionData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}