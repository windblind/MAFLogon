//
//  MAFUIFieldDescriptor.h
//
//  Copyright (c) 2012 SAP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFLogonDictionaryHelper.h"
#import "MAFLogonUIContextConstants.h"

/**
 Describes a specific field which for which user interaction needed.
*/
@interface MAFLogonUIFieldDescriptor : MAFLogonDictionaryHelper

/**
 Uniquely identifies the data field in the OperationContext
 */
@property (copy) NSString *operationContextKeyName;

/**
 Specifies what kind of field will be presented: url, phone number, number, password, email, BOOL (switch), button etc
 */
@property (copy) NSString *valueUIType;

/**
 Label text of the field.
 */
@property (copy) NSString *label;

/**
 Label localizaton key of the field.
 */
@property (copy) NSString *labelKey;

/**
 Hint text of the field.
 */
@property (copy) NSString *hintText;

/**
 Marks whether a filed should be filled out to accept data
 */
@property (assign) BOOL isMandatory;

/**
 Marks whether a field is enabled: helps to present non modifiable data
 */
@property (assign) BOOL enabled;

@end
