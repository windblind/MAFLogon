//
//  SODataMetaEntitySetDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SODataMetaEntitySet.h"

/**
 Represents the metadata of an entity set
 */
@interface SODataMetaEntitySetDefault : NSObject <SODataMetaEntitySet>

/**
 * Custon initializer
 * @param name name of the metaentity set
 * @param entityType type of the metaentity set
 * @param annotations the annotations of the metaentity set
 */
- (id) initWithName:(NSString*)name entityType:(NSString*)entityType annotations:(NSDictionary*)annotations;

@end
