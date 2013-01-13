//
//  NoPLInterface.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__NoPLInterface__
#define __NoPLGenerator__NoPLInterface__

#include <iostream>
#include "NoPLRuntime.h"

class NoPLInterface
{
public:
	
	NoPLInterface();
	~NoPLInterface();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
};

#endif /* defined(__NoPLGenerator__NoPLInterface__) */