//
//  SODataResponseDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataResponseSingle.h"

/**
 Represents a single OData response
 */
@interface SODataResponseSingleDefault : NSObject<SODataResponseSingle>

/**
 Initializer method
 @param customTag
 @param payload
 */
- (id)initWithCustomTag:(NSString*)customTag payload:(id<SODataPayload>)payload;

@end
