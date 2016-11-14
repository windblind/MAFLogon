//
//  SODataEntityDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataEntity.h"

/**
 Represents an OData entity
 */
@interface SODataEntityDefault : NSObject <SODataEntity>

/**
 * Custon initializer
 * @param type type of the Entity
 */
- (id) initWithType:(NSString*)type;

/**
 * Custon initializer
 * @param type type of the Entity
 * @param annotations the annotations of the Entity
 */
- (id) initWithType:(NSString*)type annotations:(NSDictionary *)annotations;


@end
