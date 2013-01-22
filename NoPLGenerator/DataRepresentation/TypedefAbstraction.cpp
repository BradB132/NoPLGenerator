//
//  TypedefAbstraction.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/21/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "TypedefAbstraction.h"

TypedefAbstraction::TypedefAbstraction(NoPLSchemaNode* node)
{
	//get the name as it's defined in schema
	char* sName = (char*)xmlGetProp(node->getNode(), (xmlChar*)"name");
	if(sName)
		schemaName = sName;
	
	//get the actual name
	NoPLVector<NoPLSchemaNode*>* restr = node->vectorForSchemaType(SchemaType_Restriction);
	if(restr)
	{
		NoPLSchemaNode* restrNode = restr->getVector()->at(0);
		NoPLVector<NoPLSchemaNode*>* annots = restrNode->vectorForSchemaType(SchemaType_Annotation);
		if(annots)
		{
			for(int i = 0; i < annots->getVector()->size(); i++)
			{
				xmlNodePtr node = annots->getVector()->at(i)->getNode();
				char* idValue = (char*)xmlGetProp(node, (xmlChar*)"id");
				if(idValue)
				{
					name = idValue;
					break;
				}
			}
		}
	}
}

TypedefAbstraction::~TypedefAbstraction()
{
	
}

NoPL_FunctionValue TypedefAbstraction::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//respond to length queries
	if(argc == 0)
	{
		if(!strcmp(functionName, "schemaName"))
		{
			const char* schemaName_c = schemaName.c_str();
			NoPL_assignString(schemaName_c, retVal);
		}
		else if(!strcmp(functionName, "name"))
		{
			const char* name_c = name.c_str();
			NoPL_assignString(name_c, retVal);
		}
	}
	
	return retVal;
}
