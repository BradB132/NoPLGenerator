//
//  SchemaData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__SchemaData__
#define __NoPLGenerator__SchemaData__

#include <iostream>
#include <vector>


#include "NoPLInterface.h"
#include "NoPLVector.h"
#include "ElementData.h"
#include "AttributeData.h"
#include "AttributeGroupData.h"
#include "GroupData.h"
#include "NotationData.h"
#include "SimpleTypeData.h"
#include "ComplexTypeData.h"

class SchemaData : public NoPLInterface
{
public:
	
	SchemaData();
	~SchemaData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
	//accessors
	NoPLVector<ElementData*>* getElements();
	NoPLVector<AttributeData*>* getAttributes();
	NoPLVector<AttributeGroupData*>* getAttributeGroups();
	NoPLVector<GroupData*>* getGroups();
	NoPLVector<NotationData*>* getNotations();
	NoPLVector<SimpleTypeData*>* getSimpleTypes();
	NoPLVector<ComplexTypeData*>* getComplexTypes();
	
protected:
	
	//((include|import|redefine|annotation)*,(((simpleType|complexType|group|attributeGroup)|element|attribute|notation),annotation*)*)
	
	//things that can be inside the schema tag
	NoPLVector<ElementData*>* elements;
	NoPLVector<AttributeData*>* attributes;
	NoPLVector<AttributeGroupData*>* attributeGroups;
	NoPLVector<GroupData*>* groups;
	NoPLVector<NotationData*>* notations;
	NoPLVector<SimpleTypeData*>* simpleTypes;
	NoPLVector<ComplexTypeData*>* complexTypes;
};

#endif /* defined(__NoPLGenerator__SchemaData__) */
