//
//  SchemaData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include "SchemaData.h"

#pragma mark - Constructor / Destructor

SchemaData::SchemaData():
elements(NULL),
attributes(NULL),
attributeGroups(NULL),
groups(NULL),
notations(NULL),
simpleTypes(NULL),
complexTypes(NULL)
{
	
}

SchemaData::~SchemaData()
{
	if(elements)
	{
		delete elements;
		elements = NULL;
	}
	if(attributes)
	{
		delete attributes;
		attributes = NULL;
	}
	if(attributeGroups)
	{
		delete attributeGroups;
		attributeGroups = NULL;
	}
	if(groups)
	{
		delete groups;
		groups = NULL;
	}
	if(notations)
	{
		delete notations;
		notations = NULL;
	}
	if(simpleTypes)
	{
		delete simpleTypes;
		simpleTypes = NULL;
	}
	if(complexTypes)
	{
		delete complexTypes;
		complexTypes = NULL;
	}
}

#pragma mark - lazy accessors

NoPLVector<ElementData*>* SchemaData::getElements()
{
	if(!elements)
		elements = new NoPLVector<ElementData*>();
	return elements;
}

NoPLVector<AttributeData*>* SchemaData::getAttributes()
{
	if(!attributes)
		attributes = new NoPLVector<AttributeData*>();
	return attributes;
}

NoPLVector<AttributeGroupData*>* SchemaData::getAttributeGroups()
{
	if(!attributeGroups)
		attributeGroups = new NoPLVector<AttributeGroupData*>();
	return attributeGroups;
}

NoPLVector<GroupData*>* SchemaData::getGroups()
{
	if(!groups)
		groups = new NoPLVector<GroupData*>();
	return groups;
}

NoPLVector<NotationData*>* SchemaData::getNotations()
{
	if(!notations)
		notations = new NoPLVector<NotationData*>();
	return notations;
}

NoPLVector<SimpleTypeData*>* SchemaData::getSimpleTypes()
{
	if(!simpleTypes)
		simpleTypes = new NoPLVector<SimpleTypeData*>();
	return simpleTypes;
}

NoPLVector<ComplexTypeData*>* SchemaData::getComplexTypes()
{
	if(!complexTypes)
		complexTypes = new NoPLVector<ComplexTypeData*>();
	return complexTypes;
}

#pragma mark - NoPL

NoPL_FunctionValue SchemaData::evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue SchemaData::evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}