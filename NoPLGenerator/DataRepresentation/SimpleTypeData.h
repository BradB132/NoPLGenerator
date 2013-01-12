//
//  SimpleTypeData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__SimpleTypeData__
#define __NoPLGenerator__SimpleTypeData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"
#include "RestrictionData.h"

class UnionData;


class SimpleTypeData : public SchemaBaseData
{
public:
	
	SimpleTypeData(xmlNodePtr xmlNode);
	~SimpleTypeData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(restriction|list|union))
	AnnotationData* annotation;
	RestrictionData* restriction;
//	ListData* list;
	UnionData* _union;
	
};

#endif /* defined(__NoPLGenerator__SimpleTypeData__) */
