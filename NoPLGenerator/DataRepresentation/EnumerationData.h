//
//  EnumerationData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__EnumerationData__
#define __NoPLGenerator__EnumerationData__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"

class EnumerationData : public NoPLInterface
{
public:
	
	EnumerationData();
	~EnumerationData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//no children
	
};

#endif /* defined(__NoPLGenerator__EnumerationData__) */
