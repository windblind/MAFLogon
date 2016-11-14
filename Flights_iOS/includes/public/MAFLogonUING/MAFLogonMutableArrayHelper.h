//
//  MAFLogonMutableArrayHelper.h
//  MAFLogonManagerNG
//
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Helper to handle typeless array as an typed object
 */
@interface MAFLogonMutableArrayHelper : NSMutableArray

/**
 The helper in plain array value.
 */
@property (retain) NSMutableArray* rawValue;

/**
 Class type for the contained items.
 */
@property (assign) Class           classForItems;

/**
 Initializes the class with the provided array object
 @param aRawValue NSMutableArray instance
 @param aClass Class type for the contained items
 @return initialized instance
 */
-(id) initWithRawValue:(NSMutableArray*)aRawValue classForItems:(Class)aClass;


@end
