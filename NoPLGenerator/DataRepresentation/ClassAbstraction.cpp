//
//  ClassAbstraction.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "ClassAbstraction.h"

#pragma mark - Constructor / Destructor

ClassAbstraction::ClassAbstraction(NoPLSchemaNode* schemaRoot, NoPLSchemaNode* elementNode):
className(""),
parentClassName(""),
attributes(new NoPLVector<NoPLSchemaNode*>()),
children(new NoPLVector<NoPLSchemaNode*>()),
supportsAnyAttribute(0)
{
	this->addContentFromNode(schemaRoot, elementNode);
}

ClassAbstraction::~ClassAbstraction()
{
	if(attributes)
	{
		delete attributes;
		attributes = NULL;
	}
	if(children)
	{
		delete children;
		children = NULL;
	}
}

#pragma mark - XML node traversal

void ClassAbstraction::addContentFromNode(NoPLSchemaNode* schemaRoot, NoPLSchemaNode* schemaNode)
{
	xmlNodePtr node = schemaNode->getNode();
	if(!strcmp((char*)node->name, "any"))
	{
		children->getVector()->push_back(schemaNode);
	}
	else if(!strcmp((char*)node->name, "anyAttribute"))
	{
		supportsAnyAttribute = 1;
	}
	else if(!strcmp((char*)node->name, "attribute"))
	{
		//check if this node is actually a reference to another
		char* name = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"ref"));
		if(name)
		{
			//attempt to find the actual node for this reference
			NoPLSchemaNode* referencedNode = schemaRoot->nodeWithName(SchemaType_Attribute, name);
			if(referencedNode)
				addContentFromNode(schemaRoot, referencedNode);
		}
		else
		{
			//this attribute is defined right here
			attributes->getVector()->push_back(schemaNode);
		}
	}
	else if(!strcmp((char*)node->name, "attributeGroup"))
	{
		//check if this node is actually a reference to another
		char* name = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"ref"));
		if(name)
		{
			//attempt to find the actual node for this reference
			NoPLSchemaNode* referencedNode = schemaRoot->nodeWithName(SchemaType_AttributeGroup, name);
			if(referencedNode)
				addContentFromNode(schemaRoot, referencedNode);
		}
	}
	else if(!strcmp((char*)node->name, "element"))
	{
		//check if this element is a child
		char* parentNodeType = (char*)node->parent->name;
		if(!strcmp(parentNodeType, "all") ||
		   !strcmp(parentNodeType, "sequence") )
		{
			//check if this node is actually a reference to another
			char* name = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"ref"));
			if(name)
			{
				//attempt to find the actual node for this reference
				NoPLSchemaNode* referencedNode = schemaRoot->nodeWithName(SchemaType_Element, name);
				if(referencedNode)
					children->getVector()->push_back(referencedNode);
			}
			else
			{
				//this node is not referencing anything else, just add it
				children->getVector()->push_back(schemaNode);
			}
		}
		else
		{
			//we're not a child element, check if we have a type reference
			char* typeName = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"type"));
			if(typeName)
			{
				//try looking for complex types
				NoPLSchemaNode* typeNode = schemaRoot->nodeWithName(SchemaType_ComplexType, typeName);
				if(typeNode)
					addContentFromNode(schemaRoot, typeNode);
			}
			
			//also attempt to get the className
			char* cName = (char*)xmlGetProp(node, (xmlChar*)"name");
			if(cName)
				className = cName;
		}
	}
	else if(!strcmp((char*)node->name, "extension"))
	{
		//check for the name of the parent
		char* name = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"base"));
		if(name)
			parentClassName = name;
	}
	else if(!strcmp((char*)node->name, "group"))
	{
		//check if this node is actually a reference to another
		char* name = NoPLSchemaNode::stripNamespace((char*)xmlGetProp(node, (xmlChar*)"ref"));
		if(name)
		{
			//attempt to find the actual node for this reference
			NoPLSchemaNode* referencedNode = schemaRoot->nodeWithName(SchemaType_Group, name);
			if(referencedNode)
				addContentFromNode(schemaRoot, referencedNode);
		}
	}
	
	//add children of 'all' tag
	NoPLVector<NoPLSchemaNode*>* vec = schemaNode->vectorForSchemaType(SchemaType_All);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			this->addContentFromNode(schemaRoot, vec->getVector()->at(i));
	
	//add attributes
	vec = schemaNode->vectorForSchemaType(SchemaType_Attribute);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			this->addContentFromNode(schemaRoot, vec->getVector()->at(i));
	
	//resolve attribute groups
	vec = schemaNode->vectorForSchemaType(SchemaType_AttributeGroup);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
	
	//add all complex/extension nodes
	vec = schemaNode->vectorForSchemaType(SchemaType_ComplexContent);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
	vec = schemaNode->vectorForSchemaType(SchemaType_ComplexType);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
	vec = schemaNode->vectorForSchemaType(SchemaType_Extension);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
	
	//resolve groups
	vec = schemaNode->vectorForSchemaType(SchemaType_Group);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
	
	//add children of 'sequence' tag
	vec = schemaNode->vectorForSchemaType(SchemaType_Sequence);
	if(vec)
		for(int i = 0; i < vec->getVector()->size(); i++)
			addContentFromNode(schemaRoot, vec->getVector()->at(i));
}

#pragma mark - NoPL

NoPL_FunctionValue ClassAbstraction::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	retVal.type = NoPL_DataType_Uninitialized;
	
	//we're not accepting any arguments
	if(argc == 0)
	{
		if(!strcmp(functionName, "className"))
		{
			const char* className_c = className.c_str();
			NoPL_assignString(className_c, retVal);
		}
		else if(!strcmp(functionName, "parentClassName"))
		{
			const char* className_c = parentClassName.c_str();
			NoPL_assignString(className_c, retVal);
		}
		else if(!strcmp(functionName, "attributes"))
		{
			retVal.pointerValue = attributes;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "children"))
		{
			retVal.pointerValue = children;
			retVal.type = NoPL_DataType_Pointer;
		}
		else if(!strcmp(functionName, "supportsAnyAttribute"))
		{
			retVal.booleanValue = supportsAnyAttribute;
			retVal.type = NoPL_DataType_Boolean;
		}
	}
	
	//return the result if we found one
	if(retVal.type != NoPL_DataType_Uninitialized)
		return retVal;
	return NoPLInterface::evaluateFunction(functionName, argv, argc);
}
