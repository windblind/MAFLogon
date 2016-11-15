//
//  PluginInterface.h
//  MAFLogonUING
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CertificateProviderDelegate.h"

@protocol CertificateProvider <NSObject>

/**
 Invoked during the registration, when MAFLogonManager needs a client certificate and a CertificateProvider instance is set.
 @param id<CertificateProviderDelegate> an CertificateProviderDelegate instance
**/
-(void) getCertificate:(id<CertificateProviderDelegate>) delegate;


/**
 Synch method for getting the stored client certificate. Do not present a UI here.
 Important: this method is only called when registration is already done:
 1. after unlocking secure store
 2. on application start, if secure store is not locked
 @param secIdentityRef address of a SecIdentityRef variable, which will store the returning value on success
 @param anError should contain the address of an NSError*. Will contain the address of an error on return or nil on success.
 @return BOOL: if secIdentityRef returned successfully, return YES, in every other case return NO
**/
-(BOOL) getStoredCertificate:(SecIdentityRef*)secIdentityRef error:(NSError**)anError;

/**
 CertificateProvider implementation shall delete the stored certificate when called.
 Invoked in the following cases:
 1. Application unregistration.
 2. Application registration: if any successfull registration occured in the past, this call ensures that the previously used 
    certificate will be deleted
 3. DataVault deletion because of too many failed attempts
 4. If the used certificate gets somehow invalid, and the application developer calls refreshCertificate method on the Public API of MAFLogonManager
 Return YES, if the certificate successfully deleted, or there is no certificate.
 @param anError should contain the address of an NSError*. Will contain the address of an error on return or nil on success.
 @return: YES, if Certificate successfully deleted, NO in case of any error
**/
-(BOOL) deleteStoredCertificateWithError:(NSError**)anError;


@end
