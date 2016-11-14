//
//  SODataMetaComplexTypeDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataMetaComplexType.h"

/**
 The SODataMetaComplexType element represents a complex type in an entity model. It contains zero or more properties describing properties of the complex type.
 */
@interface SODataMetaComplexTypeDefault : NSObject<SODataMetaComplexType>

/**
 * Custon initializer
 * @param properties the properties to initialize the Complex Type with
 */
- (id)initWithProperties:(NSDictionary*)properties;

@end
