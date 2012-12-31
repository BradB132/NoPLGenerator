//
//  NoPLInterface.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__NoPLInterface__
#define __NoPLGenerator__NoPLInterface__

#include <iostream>
#include "NoPLRuntime.h"

class NoPLInterface
{
public:
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc) = 0;
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index) = 0;
};

#endif /* defined(__NoPLGenerator__NoPLInterface__) */
