//
//  SchemaAbstractions.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "SchemaAbstractions.h"

#pragma mark - Constructor / Destructor

SchemaAbstractions::SchemaAbstractions(NoPLSchemaNode* node):
classes(NULL),
enums(NULL),
typedefs(NULL)
{
	//create classes by coalescing all of the information about an 'element'
	std::vector<NoPLSchemaNode*>* elements = node->vectorForSchemaType(SchemaType_Element)->getVector();
	if(elements)
	{
		//create a list for the classes
		classes = new NoPLVector<ClassAbstraction*>();
		
		//populate our classes list
		for(int i = 0; i < elements->size(); i++)
		{
			NoPLSchemaNode* element = elements->at(i);
			classes->getVector()->push_back(new ClassAbstraction(node, element));
		}
	}
}

SchemaAbstractions::~SchemaAbstractions()
{
	if(classes)
	{
		delete classes;
		classes = NULL;
	}
//	if(enums)
//	{
//		delete enums;
//		enums = NULL;
//	}
//	if(typedefs)
//	{
//		delete typedefs;
//		typedefs = NULL;
//	}
}

#pragma mark - NoPL

NoPL_FunctionValue SchemaAbstractions::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//we're not accepting any arguments
	if(argc == 0)
	{
		if(!strcmp(functionName, "classes"))
		{
			retVal.pointerValue = classes;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "enums"))
		{
			retVal.pointerValue = enums;
			retVal.type = NoPL_DataType_Pointer;
		}
		if(!strcmp(functionName, "typedefs"))
		{
			retVal.pointerValue = typedefs;
			retVal.type = NoPL_DataType_Pointer;
		}
	}
	
	//return the result if we found one
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return NoPLInterface::evaluateFunction(functionName, argv, argc);
}
