//
//  SODataErrorDefault.h
//  ODataAPI
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SODataError.h"

/**
 Represents an OData error
 */
@interface SODataErrorDefault : NSObject<SODataError>

/**
 * Custon initializer
 * @param code Error code
 * @param message Error message
 */
-(id) initWithCode:(NSString*)code message:(NSString*)message;

@end
