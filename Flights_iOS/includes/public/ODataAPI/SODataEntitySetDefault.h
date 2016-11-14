//
//  SODataEntitySetDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataEntitySet.h"

/**
 Represents an OData feed
 */
@interface SODataEntitySetDefault : NSObject<SODataEntitySet>

/**
 * Custon initializer
 * @param count size of the EntitySet
 */
-(id)initWithCount:(NSNumber*)count;

@end
