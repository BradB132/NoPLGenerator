//
//  main.m
//  NoPLGenerator
//
//  Created by Brad Bambara on 12/17/12.
//  Copyright (c) 2012 Brad Bambara. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
	//TODO: clean this up
	if(argc != 3)
	{
		NSLog(@"usage: suppy a path to an XML schema document, and a path to the NoPL generation script");
		return -1;
	}
	
	@autoreleasepool
	{
		//get file paths from args
		NSString* schemaPath = [NSString stringWithUTF8String:argv[1]];
//		NSString* scriptPath = [NSString stringWithUTF8String:argv[2]];
		
		NSError* err = nil;
		NSURL* url = [NSURL fileURLWithPath:schemaPath];
		if(!url)
		{
			NSLog(@"Can't create an URL from file %@.", schemaPath);
			return -1;
		}
		NSXMLDocument* xmlDoc = [[NSXMLDocument alloc] initWithContentsOfURL:url
																	 options:NSXMLNodePreserveCDATA
																	   error:&err];
		
		NSXMLElement* root = [xmlDoc rootElement];
		
		NSLog(@"done.");
	}
	return 0;
}
