//
//  UnionData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__UnionData__
#define __NoPLGenerator__UnionData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"
#include "SimpleTypeData.h"

class UnionData : public SchemaBaseData
{
public:
	
	UnionData(xmlNodePtr xmlNode);
	~UnionData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(simpleType*))
	AnnotationData* annotation;
	NoPLVector<SimpleTypeData*>* simpleTypes;
};

#endif /* defined(__NoPLGenerator__UnionData__) */
