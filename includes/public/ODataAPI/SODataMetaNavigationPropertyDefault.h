//
//  SODataMetaNavigationPropertyDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataMetaNavigationProperty.h"

/**
 Represents the metadata of a navigation property
 */
@interface SODataMetaNavigationPropertyDefault : NSObject <SODataMetaNavigationProperty>

/**
 * Custon initializer
 * @param name name of the navigatin property
 * @param targetEntityType type of the targer entity
 * @param isEntitySet indicates whether the taget is entity set or entity
 */
-(id) initWithName:(NSString*)name targetEntityType:(NSString*)targetEntityType isEntitySet:(BOOL)isEntitySet;

@end
