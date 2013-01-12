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
	memset(vectorList, 0, sizeof(NoPLVector<NoPLSchemaNode*>*)*SchemaTypes_TotalCount);
	
	//check all of the children of this node
	xmlNodePtr child = xmlNode->children;
	while(child)
	{
		NoPLVector<NoPLSchemaNode*>* vector = NULL;
		
		char* name = (char*)child->name;
		if(!strcmp(name, "all"))
		{
			if(!vectorList[SchemaTypes_All])
				vectorList[SchemaTypes_All] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_All];
		}
		else if(!strcmp(name, "annotation"))
		{
			if(!vectorList[SchemaTypes_Annotation])
				vectorList[SchemaTypes_Annotation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Annotation];
		}
		else if(!strcmp(name, "any"))
		{
			if(!vectorList[SchemaTypes_Any])
				vectorList[SchemaTypes_Any] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Any];
		}
		else if(!strcmp(name, "anyAttribute"))
		{
			if(!vectorList[SchemaTypes_AnyAttribute])
				vectorList[SchemaTypes_AnyAttribute] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_AnyAttribute];
		}
		else if(!strcmp(name, "appInfo"))
		{
			if(!vectorList[SchemaTypes_AppInfo])
				vectorList[SchemaTypes_AppInfo] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_AppInfo];
		}
		else if(!strcmp(name, "attribute"))
		{
			if(!vectorList[SchemaTypes_Attribute])
				vectorList[SchemaTypes_Attribute] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Attribute];
		}
		else if(!strcmp(name, "attributeGroup"))
		{
			if(!vectorList[SchemaTypes_AttributeGroup])
				vectorList[SchemaTypes_AttributeGroup] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_AttributeGroup];
		}
		else if(!strcmp(name, "choice"))
		{
			if(!vectorList[SchemaTypes_Choice])
				vectorList[SchemaTypes_Choice] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Choice];
		}
		else if(!strcmp(name, "complexContent"))
		{
			if(!vectorList[SchemaTypes_ComplexContent])
				vectorList[SchemaTypes_ComplexContent] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_ComplexContent];
		}
		else if(!strcmp(name, "complexType"))
		{
			if(!vectorList[SchemaTypes_ComplexType])
				vectorList[SchemaTypes_ComplexType] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_ComplexType];
		}
		else if(!strcmp(name, "documentation"))
		{
			if(!vectorList[SchemaTypes_Documentation])
				vectorList[SchemaTypes_Documentation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Documentation];
		}
		else if(!strcmp(name, "element"))
		{
			if(!vectorList[SchemaTypes_Element])
				vectorList[SchemaTypes_Element] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Element];
		}
		else if(!strcmp(name, "extension"))
		{
			if(!vectorList[SchemaTypes_Extension])
				vectorList[SchemaTypes_Extension] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Extension];
		}
		else if(!strcmp(name, "field"))
		{
			if(!vectorList[SchemaTypes_Field])
				vectorList[SchemaTypes_Field] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Field];
		}
		else if(!strcmp(name, "group"))
		{
			if(!vectorList[SchemaTypes_Group])
				vectorList[SchemaTypes_Group] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Group];
		}
		else if(!strcmp(name, "key"))
		{
			if(!vectorList[SchemaTypes_Key])
				vectorList[SchemaTypes_Key] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Key];
		}
		else if(!strcmp(name, "keyRef"))
		{
			if(!vectorList[SchemaTypes_KeyRef])
				vectorList[SchemaTypes_KeyRef] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_KeyRef];
		}
		else if(!strcmp(name, "list"))
		{
			if(!vectorList[SchemaTypes_List])
				vectorList[SchemaTypes_List] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_List];
		}
		else if(!strcmp(name, "notation"))
		{
			if(!vectorList[SchemaTypes_Notation])
				vectorList[SchemaTypes_Notation] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Notation];
		}
		else if(!strcmp(name, "redefine"))
		{
			if(!vectorList[SchemaTypes_Redefine])
				vectorList[SchemaTypes_Redefine] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Redefine];
		}
		else if(!strcmp(name, "restriction"))
		{
			if(!vectorList[SchemaTypes_Restriction])
				vectorList[SchemaTypes_Restriction] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Restriction];
		}
		else if(!strcmp(name, "selector"))
		{
			if(!vectorList[SchemaTypes_Selector])
				vectorList[SchemaTypes_Selector] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Selector];
		}
		else if(!strcmp(name, "sequence"))
		{
			if(!vectorList[SchemaTypes_Sequence])
				vectorList[SchemaTypes_Sequence] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Sequence];
		}
		else if(!strcmp(name, "simpleContent"))
		{
			if(!vectorList[SchemaTypes_SimpleContent])
				vectorList[SchemaTypes_SimpleContent] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_SimpleContent];
		}
		else if(!strcmp(name, "simpleType"))
		{
			if(!vectorList[SchemaTypes_SimpleType])
				vectorList[SchemaTypes_SimpleType] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_SimpleType];
		}
		else if(!strcmp(name, "union"))
		{
			if(!vectorList[SchemaTypes_Union])
				vectorList[SchemaTypes_Union] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Union];
		}
		else if(!strcmp(name, "unique"))
		{
			if(!vectorList[SchemaTypes_Unique])
				vectorList[SchemaTypes_Unique] = new NoPLVector<NoPLSchemaNode*>();
			vector = vectorList[SchemaTypes_Unique];
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
	for(int i = 0; i < SchemaTypes_TotalCount; i++)
	{
		if(vectorList[i])
		{
			delete vectorList[i];
			vectorList[i] = NULL;
		}
	}
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
		for(int i = 0; i < SchemaTypes_TotalCount; i++)
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
