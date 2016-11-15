//
//  MAFLogonManagerSupportabilitySettings.h
//  MAFLogonManagerNG
//

#import <Foundation/Foundation.h>

/**
 This class makes available the supportability settings of the MAFLogonManagerNG, the LogonUING, the CoreServices and the Request libs.
 */
@interface MAFLogonManagerSupportabilitySettings : NSObject

/**
 Gives back the shared instance of the MAFLogonManagerSupportabilitySettings.
 On this instance the SupportabilitySettings protocol methods are avaliable.
 */
+(MAFLogonManagerSupportabilitySettings*)sharedInstance;

/**
 The setter of the useSupportability BOOL flag.
 Using this setter the value will be used in all sublibraries.
 The YES value means the using of Supportability lib with the ClientLog and E2ETrace2 libs.
 The NO value means the using of the Logger and the E2ETrace libs or the NSLog.
 */
-(void)setUseSupportability:(BOOL)newUseSupportability;

/**
 The getter of the useSupportability BOOL flag
 In each library where this protocol is implemented the bool flag will be available with these accessors.
 */
-(BOOL)useSupportability;

@end
