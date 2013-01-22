//
//  SchemaAbstractions.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/12/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__SchemaAbstractions__
#define __NoPLGenerator__SchemaAbstractions__

#include <iostream>
#include "NoPLInterface.h"
#include "NoPLVector.h"
#include "NoPLSchemaNode.h"
#include "ClassAbstraction.h"
#include "EnumAbstraction.h"
#include "TypedefAbstraction.h"

class SchemaAbstractions : public NoPLInterface
{
public:
	
	SchemaAbstractions(NoPLSchemaNode* node);
	~SchemaAbstractions();
	
	//implementing NoPL interface
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	
protected:
	
	NoPLVector<ClassAbstraction*>* classes;
	NoPLVector<EnumAbstraction*>* enums;
	NoPLVector<TypedefAbstraction*>* typedefs;
	
};

#endif /* defined(__NoPLGenerator__SchemaAbstractions__) */
