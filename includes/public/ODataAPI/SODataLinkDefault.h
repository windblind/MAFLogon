//
//  SODataLinkDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataLink.h"

/**
 Represents a relationship to a resource.
 */
@interface SODataLinkDefault : NSObject<SODataLink>

/**
 * Custon initializer
 * @param resourcePath the path to initialize the link with
 */
- (id) initWithResourcePath:(NSString*)resourcePath;

@end
