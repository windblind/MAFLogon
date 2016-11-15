//
//  RequestSupportabilitySettings.h
//  Request
//
//  Copyright (c) 2014 i061647. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 This class makes available the supportability settings of the Request lib.
 */
@interface RequestSupportabilitySettings : NSObject

/**
 Flag to decide to use the Supportability library.
 Default value is NO.
 */
@property BOOL useSupportability;

/**
 Gives back the shared instance of the RequestSupportabilitySettings.
 On this instance the SupportabilitySettings protocol methods are avaliable.
 */
+(RequestSupportabilitySettings*)sharedInstance;

@end
