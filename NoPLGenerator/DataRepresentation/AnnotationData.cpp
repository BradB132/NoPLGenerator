//
//  AnnotationData.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/3/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#include "AnnotationData.h"

AnnotationData::AnnotationData(xmlNodePtr xmlNode):
appinfos(NULL),
documentation(NULL),
SchemaBaseData(xmlNode)
{
	
}

AnnotationData::~AnnotationData()
{
	
}

NoPL_FunctionValue AnnotationData::evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
{
	NoPL_FunctionValue retVal;
	return retVal;
}

NoPL_FunctionValue AnnotationData::evaluateSubscript(NoPL_FunctionValue index)
{
	NoPL_FunctionValue retVal;
	return retVal;
}