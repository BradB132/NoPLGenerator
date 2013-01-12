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
#include "SchemaBaseData.h"

class EnumerationData : public SchemaBaseData
{
public:
	
	EnumerationData(xmlNodePtr xmlNode);
	~EnumerationData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//no children
	
};

#endif /* defined(__NoPLGenerator__EnumerationData__) */
