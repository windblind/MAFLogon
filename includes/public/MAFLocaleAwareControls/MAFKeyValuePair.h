//
//  MAFKeyValuePair.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 2/29/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @class MAFKeyValuePair
 
 @brief Stores key-value pair.
 
 The MAFKeyValuePair class stores a key/value pair
 for use in the MAFValueHelpCollections.
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFKeyValuePair : NSObject
{
	NSString* key;
	NSString* value;
}


/// property holding the key part of the pair 
@property (nonatomic, readonly) NSString* key;

/// property holding the value part of the pair
@property (nonatomic, readonly) NSString* value;

/**
 Static factory method delivering a MAFKeyValuePair
 
 @param key the key part of the pair
 @param value the value part of the pair
 
*/
+ (MAFKeyValuePair*)pairWithKey:(NSString*)key andValue:(NSString*)value;

/**
 Initializer
 
 @param key the key part of the pair
 @param value the value part of the pair
 
*/
-(id)initWithKey:(NSString*)key andValue:(NSString*)value;


@end
