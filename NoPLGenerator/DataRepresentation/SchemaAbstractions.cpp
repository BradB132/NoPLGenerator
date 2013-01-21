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
	NoPLVector<NoPLSchemaNode*>* elements = node->vectorForSchemaType(SchemaType_Element);
	if(elements)
	{
		//create a list for the classes
		classes = new NoPLVector<ClassAbstraction*>();
		
		//populate our classes list
		for(int i = 0; i < elements->getVector()->size(); i++)
		{
			NoPLSchemaNode* element = elements->getVector()->at(i);
			classes->getVector()->push_back(new ClassAbstraction(node, element));
		}
	}
	
	//iterate over all of the simple types
	NoPLVector<NoPLSchemaNode*>* simpleTypes = node->vectorForSchemaType(SchemaType_SimpleType);
	if(simpleTypes)
	{
		for(int i = 0; i < simpleTypes->getVector()->size(); i++)
		{
			NoPLSchemaNode* simpleTypeNode = simpleTypes->getVector()->at(i);
			
			//examine the restriction tag in this simple type
			NoPLVector<NoPLSchemaNode*>* restr = simpleTypeNode->vectorForSchemaType(SchemaType_Restriction);
			if(restr)
			{
				//check if this is an enumeration type
				NoPLSchemaNode* restrNode = restr->getVector()->at(0);
				NoPLVector<NoPLSchemaNode*>* enumVec = restrNode->vectorForSchemaType(SchemaType_Enumeration);
				if(enumVec)
				{
					if(!enums)
						enums = new NoPLVector<EnumAbstraction*>();
					enums->getVector()->push_back(new EnumAbstraction(simpleTypeNode));
				}
			}
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
	if(enums)
	{
		delete enums;
		enums = NULL;
	}
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
