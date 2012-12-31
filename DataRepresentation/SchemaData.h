//
//  SchemaData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__SchemaData__
#define __NoPLGenerator__SchemaData__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"

class SchemaData : public NoPLInterface
{
public:
	
	SchemaData();
	~SchemaData();
	
	virtual NoPL_FunctionValue evaluateFunction(void* calledOnObject, const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(void* calledOnObject, NoPL_FunctionValue index);
	
protected:
	
	//TODO: all args
	std::string argName;
	
	//TODO: list of classes
	//TODO: list of enums
	
};

#endif /* defined(__NoPLGenerator__SchemaData__) */
