//
//  TypedefAbstraction.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/21/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__TypedefAbstraction__
#define __NoPLGenerator__TypedefAbstraction__

#include <iostream>
#include "NoPLInterface.h"
#include "NoPLSchemaNode.h"

class TypedefAbstraction : NoPLInterface
{
public:
	
	TypedefAbstraction(NoPLSchemaNode* node);
	~TypedefAbstraction();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	
protected:
	
	std::string schemaName;
	std::string name;
};

#endif /* defined(__NoPLGenerator__TypedefAbstraction__) */
