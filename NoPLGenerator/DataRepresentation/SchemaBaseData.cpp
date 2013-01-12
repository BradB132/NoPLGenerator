//
//  NotationData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "NotationData.h"

SchemaBaseData::SchemaBaseData(xmlNodePtr xmlNode):
node(xmlNode)
{
	
}

SchemaBaseData::~SchemaBaseData()
{
	
}

NoPL_FunctionValue SchemaBaseData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//double check we have the correct object
	if(argc == 0)
	{
		const xmlChar* value = xmlGetProp(node, (xmlChar*)functionName);
		if(value)
		{
			char* strValue = (char*)value;
			NoPL_assignString(strValue, retVal);
		}
	}
	
	return retVal;
}

NoPL_FunctionValue SchemaBaseData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	return retVal;
}