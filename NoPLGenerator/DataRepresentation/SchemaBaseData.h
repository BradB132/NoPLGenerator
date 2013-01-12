//
//  SchemaBaseData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__SchemaBaseData__
#define __NoPLGenerator__SchemaBaseData__

#include <iostream>
#include "NoPLRuntime.h"
#include <libxml/xmlschemastypes.h>

class SchemaBaseData
{
public:
	
	SchemaBaseData(xmlNodePtr xmlNode);
	~SchemaBaseData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//TODO: is there an actual reason for this class still?
	
	//TODO: decide if we want to expose this to script in addition to other stuff
	
	xmlNodePtr node;
};

#endif /* defined(__NoPLGenerator__SchemaBaseData__) */