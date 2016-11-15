//
//  SODataMetaPropertyDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataMetaProperty.h"

/**
 Represents the metadata of an OData property
 */
@interface SODataMetaPropertyDefault : NSObject<SODataMetaProperty>

/**
 * Custon initializer
 * @param name name of the property
 * @param type property type
 * @param typeName name of the property type
 * @param facets the facets of the property
 * @param annotations the annotations of the property
 * @param isKey indicates whether this is a key property or not
 */
- (id) initWithName:(NSString*)name type:(SODataEDMTypes)type typeName:(NSString*)typeName facets:(NSDictionary*)facets annotations:(NSDictionary*)annotations isKey:(BOOL)isKey;

@end
