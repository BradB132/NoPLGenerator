//
//  ComplexTypeData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ComplexTypeData__
#define __NoPLGenerator__ComplexTypeData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"
#include "AttributeData.h"
#include "AttributeGroupData.h"

class ComplexTypeData : public SchemaBaseData
{
public:
	
	ComplexTypeData(xmlNodePtr xmlNode);
	~ComplexTypeData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(simpleContent|complexContent|((group|all|choice|sequence)?,((attribute|attributeGroup)*,anyAttribute?))))
	AnnotationData* annotation;
	NoPLVector<AttributeData*>* attributes;
	NoPLVector<AttributeGroupData*>* attributeGroups;
	
};

#endif /* defined(__NoPLGenerator__ComplexTypeData__) */
