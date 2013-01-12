//
//  SchemaData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include "SchemaData.h"

#pragma mark - Constructor / Destructor

SchemaData::SchemaData(xmlNodePtr xmlNode):
annotations(NULL),
elements(NULL),
attributes(NULL),
attributeGroups(NULL),
groups(NULL),
notations(NULL),
simpleTypes(NULL),
complexTypes(NULL),
SchemaBaseData(xmlNode)
{
	//TODO: parse all of the namespaces
	
	//check all of the children of this node
	xmlNodePtr child = xmlNode->children;
	while(child)
	{
		if(!strcmp((char*)child->name, "annotation"))
			this->getAnnotations()->getVector()->push_back(new AnnotationData(child));
		else if(!strcmp((char*)child->name, "element"))
			this->getElements()->getVector()->push_back(new ElementData(child));
		else if(!strcmp((char*)child->name, "attribute"))
			this->getAttributes()->getVector()->push_back(new AttributeData(child));
		else if(!strcmp((char*)child->name, "attributeGroup"))
			this->getAttributeGroups()->getVector()->push_back(new AttributeGroupData(child));
		else if(!strcmp((char*)child->name, "groups"))
			this->getGroups()->getVector()->push_back(new GroupData(child));
		else if(!strcmp((char*)child->name, "notation"))
			this->getNotations()->getVector()->push_back(new NotationData(child));
		else if(!strcmp((char*)child->name, "simpleType"))
			this->getSimpleTypes()->getVector()->push_back(new SimpleTypeData(child));
		else if(!strcmp((char*)child->name, "complexType"))
			this->getComplexTypes()->getVector()->push_back(new ComplexTypeData(child));
		
		//iterate to the next child
		child = child->next;
	}
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
	if(annotations)
	{
		delete annotations;
		annotations = NULL;
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

#pragma mark - Lazy accessors

NoPLVector<AnnotationData*>* SchemaData::getAnnotations()
{
	if(!annotations)
		annotations = new NoPLVector<AnnotationData*>();
	return annotations;
}

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

NoPL_FunctionValue SchemaData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//we're not accepting any arguments
	if(argc == 0)
	{
		if(!strcmp(functionName, "annotations"))
		{
			retVal.pointerValue = annotations;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "elements"))
		{
			retVal.pointerValue = elements;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "attributes"))
		{
			retVal.pointerValue = attributes;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "attributeGroups"))
		{
			retVal.pointerValue = attributeGroups;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "groups"))
		{
			retVal.pointerValue = groups;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "notations"))
		{
			retVal.pointerValue = notations;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "simpleTypes"))
		{
			retVal.pointerValue = simpleTypes;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "complexTypes"))
		{
			retVal.pointerValue = complexTypes;
			retVal.type = NoPL_DataType_Pointer;
		}
	}
	
	//return the result if we found one
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return SchemaBaseData::evaluateFunction(functionName, argv, argc);
}

