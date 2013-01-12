//
//  NoPLVector.h
//  NoPLGenerator
//
//  Created by Brad Bambara on 1/1/13.
//  Copyright (c) 2013 Brad Bambara. All rights reserved.
//

#ifndef __NoPLGenerator__NoPLVector__
#define __NoPLGenerator__NoPLVector__

#include <iostream>
#include <vector>
#include "NoPLRuntime.h"
#include "NoPLInterface.h"

template <typename T>
class NoPLVector : public NoPLInterface
{
public:
	
	NoPLVector():
	vector(NULL)
	{
	}
	
	~NoPLVector()
	{
		if(vector != NULL)
		{
			delete vector;
			vector = NULL;
		}
	}
	
	std::vector<T>* getVector()
	{
		if(!vector)
			vector = new std::vector<T>();
		return vector;
	}
	
	virtual NoPL_FunctionValue evaluateFunction(const char* functionName, const NoPL_FunctionValue* argv, unsigned int argc)
	{
		NoPL_FunctionValue retVal;
		retVal.type = NoPL_DataType_Uninitialized;
		
		//respond to length queries
		if(argc == 0 &&
		   (!strcmp(functionName, "count") ||
			!strcmp(functionName, "size") ||
			!strcmp(functionName, "length")))
		{
			retVal.type = NoPL_DataType_Number;
			if(vector)
				retVal.numberValue = (float)vector->size();
			else
				retVal.numberValue = 0;
		}
		
		return retVal;
	}
	
	virtual NoPL_FunctionValue evaluateSubscript(NoPL_FunctionValue index)
	{
		NoPL_FunctionValue retVal;
		retVal.type = NoPL_DataType_Uninitialized;
		
		//make sure the index is numeric
		if(vector && index.type == NoPL_DataType_Number)
		{
			//make sure we're within the bounds of this array
			int intIndex = (int)index.numberValue;
			if(intIndex >= 0 && intIndex < vector->size())
			{
				retVal.type = NoPL_DataType_Pointer;
				retVal.pointerValue = vector->at(intIndex);
			}
		}
		
		return retVal;
	}
	
	std::string getTag()
	{
		return tag;
	}
	
	void setTag(std::string newTag)
	{
		tag = newTag;
	}
	
protected:
	
	std::vector<T>* vector;
	std::string tag;
};

#endif /* defined(__NoPLGenerator__NoPLVector__) */
