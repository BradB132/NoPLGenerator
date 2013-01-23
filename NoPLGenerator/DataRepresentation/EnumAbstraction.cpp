//
//  EnumAbstraction.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/13/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "EnumAbstraction.h"
#include "NoPLVector.h"

#pragma mark - Constructor / Destructor

EnumAbstraction::EnumAbstraction(NoPLSchemaNode* node):
enumValues(NULL)
{
	NoPLVector<NoPLSchemaNode*>* restr = node->vectorForSchemaType(SchemaType_Restriction);
	if(restr)
	{
		NoPLSchemaNode* restrNode = restr->getVector()->at(0);
		NoPLVector<NoPLSchemaNode*>* enums = restrNode->vectorForSchemaType(SchemaType_Enumeration);
		if(enums)
		{
			enumValues = new std::vector<NoPLSchemaNode*>();
			
			for(int i = 0; i < enums->getVector()->size(); i++)
				enumValues->push_back(enums->getVector()->at(i));
		}
	}
	
	//also attempt to get the enumName
	char* eName = (char*)xmlGetProp(node->getNode(), (xmlChar*)"name");
	if(eName)
		enumName = eName;
}

EnumAbstraction::~EnumAbstraction()
{
	if(enumValues)
	{
		delete enumValues;
		enumValues = NULL;
	}
}

#pragma mark - NoPL

NoPL_FunctionValue EnumAbstraction::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//respond to length queries
	if(argc == 0)
	{
		if(!strcmp(functionName, "count") ||
		   !strcmp(functionName, "size") ||
		   !strcmp(functionName, "length"))
		{
			retVal.type = NoPL_DataType_Number;
			if(enumValues)
				retVal.numberValue = (float)enumValues->size();
			else
				retVal.numberValue = 0;
		}
		else if(!strcmp(functionName, "enumName"))
		{
			const char* enumName_c = enumName.c_str();
			NoPL_assignString(enumName_c, retVal);
		}
	}
	
	return retVal;
}

NoPL_FunctionValue EnumAbstraction::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//make sure the index is numeric
	if(enumValues && index.type == NoPL_DataType_Number)
	{
		//make sure we're within the bounds of this array
		int intIndex = (int)index.numberValue;
		if(intIndex >= 0 && intIndex < enumValues->size())
		{
			retVal.pointerValue = enumValues->at(intIndex);
			retVal.type = NoPL_DataType_Pointer;
		}
	}
	
	return retVal;
}
