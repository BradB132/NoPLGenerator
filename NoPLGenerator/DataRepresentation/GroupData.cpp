//
//  GroupData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "GroupData.h"

GroupData::GroupData(xmlNodePtr xmlNode):
annotation(NULL),
SchemaBaseData(xmlNode)
{
	
}

GroupData::~GroupData()
{
	
}

NoPL_FunctionValue GroupData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue GroupData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}