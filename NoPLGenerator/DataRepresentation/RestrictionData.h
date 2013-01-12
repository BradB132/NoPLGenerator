//
//  RestrictionData.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/2/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__RestrictionData__
#define __NoPLGenerator__RestrictionData__

#include <iostream>
#include <vector>
#include "SchemaBaseData.h"

class RestrictionData : public SchemaBaseData
{
public:
	
	RestrictionData(xmlNodePtr xmlNode);
	~RestrictionData();
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc);
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index);
	
protected:
	
	/*
	 Content for simpleType:
	 (annotation?,(simpleType?,(minExclusive|minInclusive|
	 maxExclusive|maxInclusive|totalDigits|fractionDigits|
	 length|minLength|maxLength|enumeration|whiteSpace|pattern)*))
	 
	 Content for simpleContent:
	 (annotation?,(simpleType?,(minExclusive |minInclusive|
	 maxExclusive|maxInclusive|totalDigits|fractionDigits|
	 length|minLength|maxLength|enumeration|whiteSpace|pattern)*)?,
	 ((attribute|attributeGroup)*,anyAttribute?))
	 
	 Content for complexContent:
	 (annotation?,(group|all|choice|sequence)?,
	 ((attribute|attributeGroup)*,anyAttribute?))
	 */
	
};

#endif /* defined(__NoPLGenerator__RestrictionData__) */
