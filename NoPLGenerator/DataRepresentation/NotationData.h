//
//  NotationData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__NotationData__
#define __NoPLGenerator__NotationData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"

class NotationData : public SchemaBaseData
{
public:
	
	NotationData(xmlNodePtr xmlNode);
	~NotationData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(annotation?)
	AnnotationData* annotation;
};

#endif /* defined(__NoPLGenerator__NotationData__) */
