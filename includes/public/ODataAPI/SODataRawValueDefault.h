//
//  SODataRawValueDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataRawValue.h"

/**
 Represents the raw value of an OData property
 */
@interface SODataRawValueDefault : NSObject <SODataRawValue>

/**
 * Custon initializer
 * @param value the value to init the raw value with
 */
-(id)initWithValue:(NSString*)value;

@end
