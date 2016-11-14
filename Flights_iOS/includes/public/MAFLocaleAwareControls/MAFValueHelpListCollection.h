//
//  MAFValueHelpCollection.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 2/29/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MAFKeyValuePair.h"
#import "MAFValueHelpCollection.h"

/**
 @class MAFValueHelpListCollection
 
 @brief The MAFValueHelpListCollection holds one simple list
 of key-value pairs to be displayed in one section.
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFValueHelpListCollection : NSObject <MAFValueHelpCollection>
{
	NSMutableArray* list;
}

/// property holding the list of key-value pairs
@property (nonatomic, readonly) NSArray* list;

/**
 Adds a key-value pair to the collection.
 
 @param keyValuePair
*/
- (void) addKeyValuePair:(MAFKeyValuePair*)keyValuePair;

@end
