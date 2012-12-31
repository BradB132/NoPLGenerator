//
//  ClassData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/30/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ClassData__
#define __NoPLGenerator__ClassData__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"

class ClassData : public NoPLInterface
{
public:
	ClassData();
	~ClassData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	
};

#endif /* defined(__NoPLGenerator__ClassData__) */
