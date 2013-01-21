//
//  EnumAbstraction.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/13/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__EnumAbstraction__
#define __NoPLGenerator__EnumAbstraction__

#include <iostream>
#include <vector>
#include "NoPLInterface.h"
#include "NoPLSchemaNode.h"

class EnumAbstraction : public NoPLInterface
{
public:
	
	EnumAbstraction(NoPLSchemaNode* node);
	~EnumAbstraction();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	std::string enumName;
	std::vector<std::string>* enumValues;
};

#endif /* defined(__NoPLGenerator__EnumAbstraction__) */
