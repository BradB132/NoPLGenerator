//
//  ElementData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ElementData__
#define __NoPLGenerator__ElementData__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"

class ElementData : public NoPLInterface
{
public:
	
	ElementData();
	~ElementData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//TODO: list of classes
	//TODO: list of enums
	
};

#endif /* defined(__NoPLGenerator__ElementData__) */