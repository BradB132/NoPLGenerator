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
#include "NoPLInterface.h"

class UnionData : public NoPLInterface
{
public:
	
	UnionData();
	~UnionData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(simpleType*))
	
};

#endif /* defined(__NoPLGenerator__UnionData__) */
