//
//  AttributeData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__AttributeData__
#define __NoPLGenerator__AttributeData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"
#include "SimpleTypeData.h"

class AttributeData : public SchemaBaseData
{
public:
	
	AttributeData(xmlNodePtr xmlNode);
	~AttributeData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(simpleType?))
	
	AnnotationData* annotation;
	SimpleTypeData* simpleType;
	
};

#endif /* defined(__NoPLGenerator__AttributeData__) */
