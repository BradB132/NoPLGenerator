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
	SchemaTypes_All = 0,
	SchemaTypes_Annotation = 1,
	SchemaTypes_Any = 2,
	SchemaTypes_AnyAttribute = 3,
	SchemaTypes_AppInfo = 4,
	SchemaTypes_Attribute = 5,
	SchemaTypes_AttributeGroup = 6,
	SchemaTypes_Choice = 7,
	SchemaTypes_ComplexContent = 8,
	SchemaTypes_ComplexType = 9,
	SchemaTypes_Documentation = 10,
	SchemaTypes_Element = 11,
	SchemaTypes_Extension = 12,
	SchemaTypes_Field = 13,
	SchemaTypes_Group = 14,
	SchemaTypes_Key = 15,
	SchemaTypes_KeyRef = 16,
	SchemaTypes_List = 17,
	SchemaTypes_Notation = 18,
	SchemaTypes_Redefine = 19,
	SchemaTypes_Restriction = 20,
	SchemaTypes_Selector = 21,
	SchemaTypes_Sequence = 22,
	SchemaTypes_SimpleContent = 23,
	SchemaTypes_SimpleType = 24,
	SchemaTypes_Union = 25,
	SchemaTypes_Unique = 26,
	SchemaTypes_TotalCount = 27,
}SchemaTypes;

class NoPLSchemaNode : public NoPLInterface
{
public:
	
	NoPLSchemaNode(xmlNodePtr xmlNode);
	~NoPLSchemaNode();
	
	//implementing NoPL interface
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	
protected:
	
	//always store the libxml2 node that backs this model object
	xmlNodePtr node;
	
	//store lists of all of the types of nodes that could exist here
	NoPLVector<NoPLSchemaNode*>* vectorList[SchemaTypes_TotalCount];
};

#endif /* defined(__NoPLGenerator__NoPLSchemaNode__) */
