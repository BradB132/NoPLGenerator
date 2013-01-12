//
//  AttributeGroupData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__AttributeGroupData__
#define __NoPLGenerator__AttributeGroupData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AttributeData.h"
#include "AttributeGroupData.h"

class AttributeGroupData : public SchemaBaseData
{
public:
	
	AttributeGroupData(xmlNodePtr xmlNode);
	~AttributeGroupData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?),((attribute|attributeGroup)*,anyAttribute?))
	AnnotationData* annotation;
	NoPLVector<AttributeData*>* attributes;
	NoPLVector<AttributeGroupData*>* attributeGroups;
	
};

#endif /* defined(__NoPLGenerator__AttributeGroupData__) */
