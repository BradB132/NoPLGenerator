//
//  NoPLSchemaNode.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__NoPLSchemaNode__
#define __NoPLGenerator__NoPLSchemaNode__

#include <iostream>
#include "NoPLRuntime.h"
#include "NoPLInterface.h"
#include "NoPLVector.h"
#include <libxml/xmlschemastypes.h>

typedef enum
{
	SchemaType_All = 0,
	SchemaType_Annotation = 1,
	SchemaType_Any = 2,
	SchemaType_AnyAttribute = 3,
	SchemaType_AppInfo = 4,
	SchemaType_Attribute = 5,
	SchemaType_AttributeGroup = 6,
	SchemaType_Choice = 7,
	SchemaType_ComplexContent = 8,
	SchemaType_ComplexType = 9,
	SchemaType_Documentation = 10,
	SchemaType_Element = 11,
	SchemaType_Enumeration = 12,
	SchemaType_Extension = 13,
	SchemaType_Field = 14,
	SchemaType_FractionDigits = 15,
	SchemaType_Group = 16,
	SchemaType_Key = 17,
	SchemaType_KeyRef = 18,
	SchemaType_Length = 19,
	SchemaType_List = 20,
	SchemaType_MaxExclusive = 21,
	SchemaType_MaxInclusive = 22,
	SchemaType_MaxLength = 23,
	SchemaType_MinExclusive = 24,
	SchemaType_MinInclusive = 25,
	SchemaType_MinLength = 26,
	SchemaType_Notation = 27,
	SchemaType_Pattern = 28,
	SchemaType_Redefine = 29,
	SchemaType_Restriction = 30,
	SchemaType_Selector = 31,
	SchemaType_Sequence = 32,
	SchemaType_SimpleContent = 33,
	SchemaType_SimpleType = 34,
	SchemaType_TotalDigits = 35,
	SchemaType_Union = 36,
	SchemaType_Unique = 37,
	SchemaType_WhiteSpace = 38,
	SchemaType_TotalCount = 39,
}SchemaType;

class NoPLSchemaNode : public NoPLInterface
{
public:
	
	NoPLSchemaNode(xmlNodePtr xmlNode);
	~NoPLSchemaNode();
	
	//implementing NoPL interface
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
	//abstraction accessors
	virtual NoPLVector<NoPLSchemaNode*>* vectorForSchemaType(SchemaType type);
	virtual NoPLSchemaNode* nodeWithName(SchemaType type, char* name);
	virtual xmlNodePtr getNode();
	
	//utils
	static char* stripNamespace(char* stringWithNamespace);
	
protected:
	
	//always store the libxml2 node that backs this model object
	xmlNodePtr node;
	
	//store lists of all of the types of nodes that could exist here
	NoPLVector<NoPLSchemaNode*>* vectorList[SchemaType_TotalCount];
};

#endif /* defined(__NoPLGenerator__NoPLSchemaNode__) */
