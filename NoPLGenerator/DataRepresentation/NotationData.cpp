//
//  NotationData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "NotationData.h"

NotationData::NotationData(xmlNodePtr xmlNode):
annotation(NULL),
SchemaBaseData(xmlNode)
{
	
}

NotationData::~NotationData()
{
	
}

NoPL_FunctionValue NotationData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue NotationData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}