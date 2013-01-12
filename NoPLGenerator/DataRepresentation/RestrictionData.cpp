//
//  RestrictionData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "RestrictionData.h"

RestrictionData::RestrictionData(xmlNodePtr xmlNode):
SchemaBaseData(xmlNode)
{
	
}

RestrictionData::~RestrictionData()
{
	
}

NoPL_FunctionValue RestrictionData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue RestrictionData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}