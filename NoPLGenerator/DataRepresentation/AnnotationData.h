//
//  AnnotationData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/3/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__AnnotationData__
#define __NoPLGenerator__AnnotationData__

#include <iostream>
#include <vector>

#include "NoPLVector.h"
#include "SchemaBaseData.h"
#include "AnnotationChildData.h"

class AnnotationData : public SchemaBaseData
{
public:
	
	AnnotationData(xmlNodePtr xmlNode);
	~AnnotationData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//(appinfo|documentation)*
	NoPLVector<AnnotationChildData*>* appinfos;
	NoPLVector<AnnotationChildData*>* documentation;
};

#endif /* defined(__NoPLGenerator__AnnotationData__) */
