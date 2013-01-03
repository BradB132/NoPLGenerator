//
//  ComplexTypeData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ComplexTypeData__
#define __NoPLGenerator__ComplexTypeData__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"

class ComplexTypeData : public NoPLInterface
{
public:
	
	ComplexTypeData();
	~ComplexTypeData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//(annotation?,(simpleContent|complexContent|((group|all|choice|sequence)?,((attribute|attributeGroup)*,anyAttribute?))))
	
};

#endif /* defined(__NoPLGenerator__ComplexTypeData__) */
