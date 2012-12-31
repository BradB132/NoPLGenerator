//
//  main.cpp
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/29/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#include <iostream>
#include "SchemaData.h"
#include "NoPLc.h"
#include "NoPLRuntime.h"

#pragma mark - NoPL callbacks

//TODO: nopl callbacks

#pragma mark - main

int main(int argc, const char * argv[])
{
	if(argc != 3)
	{
		printf("NoPLGenerator requires 2 arguments: path to XML Schema file and path to NoPL script file");
		return -1;
	}
	
	//get the args
	const char* schemaFilePath = argv[1];
	const char* scriptFilePath = argv[2];
	
	
	
    return 0;
}
