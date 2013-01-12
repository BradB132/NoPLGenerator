//
//  AnnotationChildData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/3/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__AnnotationChildData__
#define __NoPLGenerator__AnnotationChildData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"

class AnnotationChildData : public SchemaBaseData
{
public:
	
	AnnotationChildData(xmlNodePtr xmlNode);
	~AnnotationChildData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//could be 'appinfo' or 'documentation'
	
};

#endif /* defined(__NoPLGenerator__AnnotationChildData__) */
