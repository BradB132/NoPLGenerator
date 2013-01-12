//
//  AnnotationChildData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/3/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "AnnotationChildData.h"

AnnotationChildData::AnnotationChildData(xmlNodePtr xmlNode):
SchemaBaseData(NULL)
{
	
}

AnnotationChildData::~AnnotationChildData()
{
	
}

NoPL_FunctionValue AnnotationChildData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue AnnotationChildData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}