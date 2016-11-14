//
//  MAFApplicationSettingsReadOnlyProperty.h
//  MAFLogonManagerNG
//
//  Copyright (c) 2015 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFApplicationSettingsMetaProperty.h"

@interface MAFApplicationSettingsReadOnlyProperty : MAFApplicationSettingsMetaProperty

/**
 * Value of the property
 */
@property (nonatomic, readonly, retain) id value;

/**
 * Generates an XML part from property
 */
-(NSString*) toXML;

@end
