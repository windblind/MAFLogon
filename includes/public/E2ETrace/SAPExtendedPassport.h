//
//  SAPExtendedPassport.h
//  E2ETrace lib
//
//  Copyright 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import "E2EConstants.h"

/**
 * SAP Extended Passport
 * Usage:
 * <pre>
 * <code>
 * SAP_ExtendedPassport* passport = [SAP_ExtendedPassport createPassport];
 *
 * [m_HTTPRequest addRequestHeader:@“SAP-PASSPORT“ value:[passport passportHttpHeader]];
 * [m_HTTPRequest addRequestHeader:@“X-CorrelationID“ value:[passport corrrelationIdHttpHeader]];
 * </code>
 * </pre>
 */
@interface SAP_ExtendedPassport : NSObject

@property (nonatomic, readonly) NSString* passportHttpHeader;      ///< “SAP-PASSPORT“ header value
@property (nonatomic, readonly) NSString* correlationIdHttpHeader; ///< “X-CorrelationID“ header value


/**
 *  Creates a SAPExtendedPassport instance initialized with defaults (medium trace level and auto generated UID)
 */
+ (SAP_ExtendedPassport*) createPassport;

/**
 *  Creates a SAPExtendedPassport instance initialized with the provided root ID, trace level and auto generated UID
 */
+ (SAP_ExtendedPassport*) createPassportWithRootId:(NSData*)rootId_in andTraceLevel:(E_E2E_TRACELEVEL)traceLevel_in;

/**
 * Initializes a Passport object
 * @remark transportId and terminalId will be set to nil
 */
- (instancetype) initWithRootId:(NSData*)rootId_in andTraceLevel:(E_E2E_TRACELEVEL)traceLevel_in;

/**
 * Initializes a Passport object
 */
- (instancetype) initWithRootId:(NSData*)rootId_in
		andTraceLevel:(E_E2E_TRACELEVEL)traceLevel_in 
	   andTransportId:(NSData*)transportId_in
		andTerminalId:(NSData*)terminalId_in;

@end