//
//  SODataMetaEntityContainerDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SODataMetaEntityContainer.h"

/**
 Represents an OData EntityContainer
 */
@interface SODataMetaEntityContainerDefault : NSObject <SODataMetaEntityContainer>

/**
 * Custon initializer
 * @param functionImports the function imports of the entity container
 * @param entitySets the entity sets of the entity container
 * @param annotations the annotations of the entity container
 */
- (id)initWithFunctionImports:(NSDictionary*)functionImports entitySets:(NSDictionary*)entitySets annotations:(NSDictionary*)annotations;

@end
