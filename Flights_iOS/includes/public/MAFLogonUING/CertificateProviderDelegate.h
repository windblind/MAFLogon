//
//  PluginDelegate.h
//  MAFLogonUING
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol CertificateProviderDelegate <NSObject>

/**
 Returns the current UIViewController, which can be used for present own screen(s).
 @return rootUIViewController;
**/
-(UIViewController*) currentViewController;

/**
 Delegate method to notify the CertificateProviderDelegate implementation when SecIdentityRef successfully loaded
 @param secIdentityRef : (SecIdentityRef)
 **/
-(void) onGetCertificateSuccess:(SecIdentityRef) aCertObject;

/**
 Delegate method to notify the CertificateProviderDelegate implementation when SecIdentityRef could not be loaded
 @param error : NSError* instance, which contains the error description
 **/
-(void) onGetCertificateFailure:(NSError*) error;

@end
