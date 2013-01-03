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
#include "NoPLInterface.h"

class SimpleTypeData : public NoPLInterface
{
public:
	
	SimpleTypeData();
	~SimpleTypeData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(restriction|list|union))
	
};

#endif /* defined(__NoPLGenerator__SimpleTypeData__) */
