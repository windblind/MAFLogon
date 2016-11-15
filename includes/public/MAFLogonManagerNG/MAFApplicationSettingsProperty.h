//
//  MAFApplicationSettingsProperty.h
//  MAFLogonManagerNG
//
//  Copyright (c) 2015 SAP AG. All rights reserved.
//

#import "MAFApplicationSettingsReadOnlyProperty.h"

@interface MAFApplicationSettingsProperty : MAFApplicationSettingsReadOnlyProperty

/**
 * Return YES if the property is modified
 */
@property (nonatomic, readonly, assign) BOOL isDirty;

/**
 * Set the value of the property
 * @param value value of the property
 * @param error error pointer to be able to sign whether an error is happened
 */
- (BOOL) setValue:(id)value error:(NSError**)error;

@end
