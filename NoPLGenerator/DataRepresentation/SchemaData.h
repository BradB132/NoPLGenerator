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

#include "NoPLVector.h"
#include "SchemaBaseData.h"
#include "ElementData.h"
#include "AttributeData.h"
#include "AttributeGroupData.h"
#include "GroupData.h"
#include "AnnotationData.h"
#include "NotationData.h"
#include "SimpleTypeData.h"
#include "ComplexTypeData.h"

class SchemaData : public SchemaBaseData
{
public:
	
	SchemaData(xmlNodePtr xmlNode);
	~SchemaData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
	//accessors
	NoPLVector<ElementData*>* getElements();
	NoPLVector<AttributeData*>* getAttributes();
	NoPLVector<AttributeGroupData*>* getAttributeGroups();
	NoPLVector<GroupData*>* getGroups();
	NoPLVector<AnnotationData*>* getAnnotations();
	NoPLVector<NotationData*>* getNotations();
	NoPLVector<SimpleTypeData*>* getSimpleTypes();
	NoPLVector<ComplexTypeData*>* getComplexTypes();
	
protected:
	
	//((include|import|redefine|annotation)*,(((simpleType|complexType|group|attributeGroup)|element|attribute|notation),annotation*)*)
	xmlSchemaPtr _schema;
	
	AnnotationData* annotation;
	NoPLVector<ElementData*>* elements;
	NoPLVector<AttributeData*>* attributes;
	NoPLVector<AttributeGroupData*>* attributeGroups;
	NoPLVector<GroupData*>* groups;
	NoPLVector<NotationData*>* notations;
	NoPLVector<SimpleTypeData*>* simpleTypes;
	NoPLVector<ComplexTypeData*>* complexTypes;
};

#endif /* defined(__NoPLGenerator__SchemaData__) */
