//
//  ClassAbstraction.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ClassAbstraction__
#define __NoPLGenerator__ClassAbstraction__

#include <iostream>
#include "NoPLInterface.h"
#include "NoPLVector.h"
#include "NoPLSchemaNode.h"

class ClassAbstraction : public NoPLInterface
{
public:
	
	ClassAbstraction(NoPLSchemaNode* schemaRoot, NoPLSchemaNode* elementNode);
	~ClassAbstraction();
	
	//implementing NoPL interface
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	
protected:
	
	virtual void addContentFromNode(NoPLSchemaNode* schemaRoot, NoPLSchemaNode* schemaNode);
	
	std::string className;
	std::string parentClassName;
	NoPLVector<NoPLSchemaNode*>* attributes;
	NoPLVector<NoPLSchemaNode*>* children;
	int supportsAnyAttribute;
};

#endif /* defined(__NoPLGenerator__ClassAbstraction__) */
