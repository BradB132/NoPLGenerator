//
//  ElementData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "ElementData.h"

ElementData::ElementData(xmlNodePtr xmlNode):
annotation(NULL),
simpleType(NULL),
complexType(NULL),
SchemaBaseData(xmlNode)
{
	//loop through all children
	xmlNodePtr child = xmlNode->children;
	while(child)
	{
		if(!strcmp((char*)child->name, "complexType"))
		{
			xmlNodePtr complexChild = child->children;
			while(complexChild)
			{
				printf("COMPLEX CHILD: %s", complexChild->name);
				complexChild = complexChild->next;
			}
		}
		
		
		child = child->next;
	}
}

ElementData::~ElementData()
{
	
}

NoPL_FunctionValue ElementData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue ElementData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}