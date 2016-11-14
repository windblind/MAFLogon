//
//  Request.h
//  E2ETrace lib
//
//  Copyright 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SUPE2ETraceStep.h"
#import "SAPExtendedPassport.h"


@interface SUPE2ETraceRequest : NSObject
@property (nonatomic, readonly, retain) NSString* name;
@property (nonatomic, readonly, retain) NSDictionary* requestDict;
@property (nonatomic, readonly, retain) NSData* transactionId;
@property (nonatomic, readonly, retain) SAP_ExtendedPassport* extSAPPassport;

/**
 *  Creates an E2ETraceRequest
 *  The request created receives default attributes.
 *  Request timestamp is set to the time of initialization.
 *  SAP-PASSPORT and X-CorrelationID http headers are created.
 *
 *  @param id_in sets the request's optional name
 *
 *  @return E2ETraceRequest
 */
+ (SUPE2ETraceRequest*) createRequest:(NSString*)id_in;

/**
 * Retrieves the @“SAP-PASSPORT“ header value.
 * <pre>
 * Usage
 * <code>
 * [m_HTTPRequest addRequestHeader:@“SAP-PASSPORT“ value:[theRequest PassportHttpHeader]];
 * </code>
 * </pre>
 */
- (NSString*) PassportHttpHeader;

/**
 * Retrieves the @“X-CorrelationID“ header value.
 * <pre>
 * Usage
 * <code>
 * [m_HTTPRequest addRequestHeader:@“X-CorrelationID“ value:[theRequest CorrelationIdHttpHeader]]; 
 * </code>
 * </pre>
 */
- (NSString*) CorrelationIdHttpHeader;

/**
 * Should be called before the request is sent out.
 */
- (void) markSending;

/**
 * Should be called as soon as the data is being sent.
 */
- (void) markSent;

/**
 * When the first data is being received.
 */
- (void) markReceiving;

/**
 * When all data from the response have been received call this.
 */
- (void) markReceived;

- (BOOL) updateRequestWithValue:(NSString*)value_in forKey:(NSString *)key_in;

- (BOOL) updateRequestElementsWithDictionary:(NSDictionary*)dictionary_in;

/**
 * At the end when response is received.
 * @return YES if ending the request was succesful
 */
- (BOOL) endRequest;

/**
 *  Creates and returns the Transaction Request XML
 *  This will be appended to the Transaction Step XML, which in turn is appended to the Busieness transaction XML
 *  @return Transaction Request XML as string
 */
- (NSString *) getXML;
@end
