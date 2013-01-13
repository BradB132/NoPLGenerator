//
//  NoPLSchemaNode.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "NoPLSchemaNode.h"

#pragma mark - Constructor / Destructor

NoPLSchemaNode::NoPLSchemaNode(xmlNodePtr xmlNode):
node(xmlNode)
{
	//make sure we NULL out the vector list
	memset(vectorList, 0, sizeof(NoPLVector<NoPLSchemaNode*>*)*SchemaType_TotalCount);
	
	//check all of the children of this node
	xmlNodePtr child = xmlNode->children;
	while(child)
	{
		NoPLVector<NoPLSchemaNode*>* vector = NULL;
		
		char* name = (char*)child->name;
		if(!strcmp(name, "all"))
		{
			if(!vectorList[SchemaType_All])
				vectorList[SchemaType_All] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_All];
		}
		else if(!strcmp(name, "annotation"))
		{
			if(!vectorList[SchemaType_Annotation])
				vectorList[SchemaType_Annotation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Annotation];
		}
		else if(!strcmp(name, "any"))
		{
			if(!vectorList[SchemaType_Any])
				vectorList[SchemaType_Any] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Any];
		}
		else if(!strcmp(name, "anyAttribute"))
		{
			if(!vectorList[SchemaType_AnyAttribute])
				vectorList[SchemaType_AnyAttribute] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_AnyAttribute];
		}
		else if(!strcmp(name, "appInfo"))
		{
			if(!vectorList[SchemaType_AppInfo])
				vectorList[SchemaType_AppInfo] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_AppInfo];
		}
		else if(!strcmp(name, "attribute"))
		{
			if(!vectorList[SchemaType_Attribute])
				vectorList[SchemaType_Attribute] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Attribute];
		}
		else if(!strcmp(name, "attributeGroup"))
		{
			if(!vectorList[SchemaType_AttributeGroup])
				vectorList[SchemaType_AttributeGroup] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_AttributeGroup];
		}
		else if(!strcmp(name, "choice"))
		{
			if(!vectorList[SchemaType_Choice])
				vectorList[SchemaType_Choice] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Choice];
		}
		else if(!strcmp(name, "complexContent"))
		{
			if(!vectorList[SchemaType_ComplexContent])
				vectorList[SchemaType_ComplexContent] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_ComplexContent];
		}
		else if(!strcmp(name, "complexType"))
		{
			if(!vectorList[SchemaType_ComplexType])
				vectorList[SchemaType_ComplexType] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_ComplexType];
		}
		else if(!strcmp(name, "documentation"))
		{
			if(!vectorList[SchemaType_Documentation])
				vectorList[SchemaType_Documentation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Documentation];
		}
		else if(!strcmp(name, "element"))
		{
			if(!vectorList[SchemaType_Element])
				vectorList[SchemaType_Element] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Element];
		}
		else if(!strcmp(name, "enumeration"))
		{
			if(!vectorList[SchemaType_Enumeration])
				vectorList[SchemaType_Enumeration] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Enumeration];
		}
		else if(!strcmp(name, "extension"))
		{
			if(!vectorList[SchemaType_Extension])
				vectorList[SchemaType_Extension] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Extension];
		}
		else if(!strcmp(name, "field"))
		{
			if(!vectorList[SchemaType_Field])
				vectorList[SchemaType_Field] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Field];
		}
		else if(!strcmp(name, "fractionDigits"))
		{
			if(!vectorList[SchemaType_FractionDigits])
				vectorList[SchemaType_FractionDigits] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_FractionDigits];
		}
		else if(!strcmp(name, "group"))
		{
			if(!vectorList[SchemaType_Group])
				vectorList[SchemaType_Group] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Group];
		}
		else if(!strcmp(name, "key"))
		{
			if(!vectorList[SchemaType_Key])
				vectorList[SchemaType_Key] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Key];
		}
		else if(!strcmp(name, "keyRef"))
		{
			if(!vectorList[SchemaType_KeyRef])
				vectorList[SchemaType_KeyRef] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_KeyRef];
		}
		else if(!strcmp(name, "length"))
		{
			if(!vectorList[SchemaType_Length])
				vectorList[SchemaType_Length] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Length];
		}
		else if(!strcmp(name, "list"))
		{
			if(!vectorList[SchemaType_List])
				vectorList[SchemaType_List] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_List];
		}
		else if(!strcmp(name, "maxExclusive"))
		{
			if(!vectorList[SchemaType_MaxExclusive])
				vectorList[SchemaType_MaxExclusive] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MaxExclusive];
		}
		else if(!strcmp(name, "maxInclusive"))
		{
			if(!vectorList[SchemaType_MaxInclusive])
				vectorList[SchemaType_MaxInclusive] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MaxInclusive];
		}
		else if(!strcmp(name, "maxLength"))
		{
			if(!vectorList[SchemaType_MaxLength])
				vectorList[SchemaType_MaxLength] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MaxLength];
		}
		else if(!strcmp(name, "minExclusive"))
		{
			if(!vectorList[SchemaType_MinExclusive])
				vectorList[SchemaType_MinExclusive] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MinExclusive];
		}
		else if(!strcmp(name, "minInclusive"))
		{
			if(!vectorList[SchemaType_MinInclusive])
				vectorList[SchemaType_MinInclusive] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MinInclusive];
		}
		else if(!strcmp(name, "minLength"))
		{
			if(!vectorList[SchemaType_MinLength])
				vectorList[SchemaType_MinLength] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_MinLength];
		}
		else if(!strcmp(name, "notation"))
		{
			if(!vectorList[SchemaType_Notation])
				vectorList[SchemaType_Notation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Notation];
		}
		else if(!strcmp(name, "pattern"))
		{
			if(!vectorList[SchemaType_Pattern])
				vectorList[SchemaType_Pattern] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Pattern];
		}
		else if(!strcmp(name, "redefine"))
		{
			if(!vectorList[SchemaType_Redefine])
				vectorList[SchemaType_Redefine] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Redefine];
		}
		else if(!strcmp(name, "restriction"))
		{
			if(!vectorList[SchemaType_Restriction])
				vectorList[SchemaType_Restriction] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Restriction];
		}
		else if(!strcmp(name, "selector"))
		{
			if(!vectorList[SchemaType_Selector])
				vectorList[SchemaType_Selector] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Selector];
		}
		else if(!strcmp(name, "sequence"))
		{
			if(!vectorList[SchemaType_Sequence])
				vectorList[SchemaType_Sequence] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Sequence];
		}
		else if(!strcmp(name, "simpleContent"))
		{
			if(!vectorList[SchemaType_SimpleContent])
				vectorList[SchemaType_SimpleContent] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_SimpleContent];
		}
		else if(!strcmp(name, "simpleType"))
		{
			if(!vectorList[SchemaType_SimpleType])
				vectorList[SchemaType_SimpleType] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_SimpleType];
		}
		else if(!strcmp(name, "totalDigits"))
		{
			if(!vectorList[SchemaType_TotalDigits])
				vectorList[SchemaType_TotalDigits] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_TotalDigits];
		}
		else if(!strcmp(name, "union"))
		{
			if(!vectorList[SchemaType_Union])
				vectorList[SchemaType_Union] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Union];
		}
		else if(!strcmp(name, "unique"))
		{
			if(!vectorList[SchemaType_Unique])
				vectorList[SchemaType_Unique] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_Unique];
		}
		else if(!strcmp(name, "whiteSpace"))
		{
			if(!vectorList[SchemaType_WhiteSpace])
				vectorList[SchemaType_WhiteSpace] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaType_WhiteSpace];
		}
		
		//we should definitely have a vector, let's check just to be safe
		if(vector)
		{
			//set the correct type name on this vector
			vector->setTag((char*)child->name);
			
			//add a new child to this list
			vector->getVector()->push_back(new NoPLSchemaNode(child));
		}
		
		//iterate to the next child
		child = child->next;
	}
}

NoPLSchemaNode::~NoPLSchemaNode()
{
	//free any vectors that were allocated
	for(int i = 0; i < SchemaType_TotalCount; i++)
	{
		if(vectorList[i])
		{
			delete vectorList[i];
			vectorList[i] = NULL;
		}
	}
}

#pragma mark - Abstraction accessors

NoPLVector<NoPLSchemaNode*>* NoPLSchemaNode::vectorForSchemaType(SchemaType type)
{
	return vectorList[type];
}

NoPLSchemaNode* NoPLSchemaNode::nodeWithName(SchemaType type, char* name)
{
	//get the vector of nodes that matches the type
	if(vectorList[type])
	{
		std::vector<NoPLSchemaNode*>* vec = vectorList[type]->getVector();
		if(vec)
		{
			//search the vector for a node containing a 'name' attribute which matches the name arg
			for(int i = 0; i < vec->size(); i++)
			{
				NoPLSchemaNode* node = vec->at(i);
				if(!strcmp((char*)xmlGetProp(node->getNode(), (xmlChar*)"name"), name))
				{
					return node;
				}
			}
		}
	}
	
	return NULL;
}

xmlNodePtr NoPLSchemaNode::getNode()
{
	return node;
}

#pragma mark - Util

char* NoPLSchemaNode::stripNamespace(char* stringWithNamespace)
{
	if(stringWithNamespace)
	{
		//strip the namespacing
		char* shortened = strrchr(stringWithNamespace, ':');
		if(shortened)
			return shortened+1;
	}
	return stringWithNamespace;
}

#pragma mark - NoPL

NoPL_FunctionValue NoPLSchemaNode::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//we're not accepting any arguments
	if(argc == 0)
	{
		//check if the NoPL script is asking for one of our lists
		for(int i = 0; i < SchemaType_TotalCount; i++)
		{
			//skip empty lists
			if(vectorList[i])
			{
				if(!strcmp(functionName, vectorList[i]->getTag().c_str()))
				{
					//the script has asked for a singular item, return the first one in the list
					retVal.pointerValue = vectorList[i]->getVector()->at(0);
					retVal.type = NoPL_DataType_Pointer;
					break;
				}
				else
				{
					//pluralize the tag by appending an 's' character
					static char* concatString[50];
					strncpy((char*)concatString, vectorList[i]->getTag().c_str(), 49);
					strncat((char*)concatString, "s", 49);
					
					//check if the script has asked for the pluralized name
					if(!strcmp(functionName, (char*)concatString))
					{
						retVal.pointerValue = vectorList[i];
						retVal.type = NoPL_DataType_Pointer;
						break;
					}
				}
			}
		}
		
		//check if we haven't already found a value
		if(retVal.type == NoPL_DataType_Uninitialized)
		{
			//we're not getting any of the lists, check for attributes on this XML tag
			const xmlChar* value = xmlGetProp(node, (xmlChar*)functionName);
			if(value)
			{
				char* strValue = (char*)value;
				NoPL_assignString(strValue, retVal);
			}
		}
	}
	
	//return the result if we found one
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return NoPLInterface::evaluateFunction(functionName, argv, argc);
}
