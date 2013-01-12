//
//  ElementData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__ElementData__
#define __NoPLGenerator__ElementData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"
#include "AnnotationData.h"
#include "SimpleTypeData.h"
#include "ComplexTypeData.h"

class ElementData : public SchemaBaseData
{
public:
	
	ElementData(xmlNodePtr xmlNode);
	~ElementData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	//annotation?,((simpleType|complexType)?,(unique|key|keyref)*))
	AnnotationData* annotation;
	SimpleTypeData* simpleType;
	ComplexTypeData* complexType;
};

#endif /* defined(__NoPLGenerator__ElementData__) */
