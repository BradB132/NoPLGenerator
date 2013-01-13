//
//  NoPLInterface.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "NoPLInterface.h"

NoPLInterface::NoPLInterface()
{
	
}

NoPLInterface::~NoPLInterface()
{
	
}

NoPL_FunctionValue NoPLInterface::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue val;
	val.type = NoPL_DataType_Uninitialized;
	return val;
}

NoPL_FunctionValue NoPLInterface::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue val;
	val.type = NoPL_DataType_Uninitialized;
	return val;
}