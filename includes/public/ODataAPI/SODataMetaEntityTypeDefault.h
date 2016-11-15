//
//  SODataMetaEntityTypeDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataMetaEntityType.h"

/**
 Represents the metadata of an entity type
 */
@interface SODataMetaEntityTypeDefault : NSObject<SODataMetaEntityType>

/**
 * Custon initializer
 * @param metadata the metadata in String format
 * @param metaNamespaces namespaces of the metadata
 * @param resourcePath the actual resourcePath
 * @param latestResourcePath the latest resourcepath
 * @param metaEntities the entities of the metadata
 * @param metaComplex the complex types of the metadata
 * @param metaEntityContainers the entity containers
 */
- (id) initWithName:(NSString*)name isMediaEntity:(BOOL)isMediaEntity properties:(NSDictionary*)properties keyPropertyNames:(NSArray*)keyPropertyNames navigationProperties:(NSDictionary*)navigationProperties annotations:(NSDictionary*)annotations;

@end
