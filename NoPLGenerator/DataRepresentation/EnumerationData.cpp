//
//  EnumerationData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "EnumerationData.h"

EnumerationData::EnumerationData(xmlNodePtr xmlNode):
SchemaBaseData(xmlNode)
{
	
}

EnumerationData::~EnumerationData()
{
	
}

NoPL_FunctionValue EnumerationData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue EnumerationData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}