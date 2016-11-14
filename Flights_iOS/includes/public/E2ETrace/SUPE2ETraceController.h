//
//  TraceController.h
//  E2ETrace lib
//
//  Copyright 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <UIKit/UIKit.h>
#import "E2EConstants.h"
#import "SUPE2ETraceTransaction.h"
#import "SUPE2ETraceStep.h"
#import "SUPE2ETraceRequest.h"


/**
 * Facade class for the E2E trace feature
 * Usage
 * <pre>
 * <code>
 * SUPE2ETraceController* TraceHandler = [SUPE2ETraceController sharedController];
 * SUPE2ETraceTransaction* trx = [TraceHandler createTransaction];
 * SUPE2ETraceStep* step = [trx createStep];
 * SUPE2ETraceRequest* request = [step createRequest];
 * </code>
 * </pre>
 *
 * <pre>
 * <code>
 * [m_HTTPRequest addRequestHeader:@“SAP-PASSPORT“ value:[request PassportHttpHeader]];
 * [m_HTTPRequest addRequestHeader:@“X-CorrelationID“ value:[request CorrelationIdHttpHeader]];
 * </code>
 */
@interface SUPE2ETraceController: NSObject

@property (nonatomic, assign) E_E2E_TRACELEVEL traceLevel;                      ///< The verbosity of the E2E trace can be set using trace levels @see TraceLevel
@property (readonly, nonatomic, strong) SUPE2ETraceTransaction* transaction;    ///< The current transaction; must be created before steps and requests are started
@property (readonly, strong) SUPE2ETraceStep* currentStep;                      ///< The current step; requests must be started in the context of a given step
@property (readonly, strong) SUPE2ETraceRequest* currentRequest;                ///< The active E2E trace request


+ (SUPE2ETraceController*) sharedController;    ///< Singleton instance

#pragma mark - Transaction methods
- (SUPE2ETraceTransaction*) createTransaction;

- (SUPE2ETraceTransaction*) createTransactionWithName:(NSString*)transactionName withClientHost:(NSString*)clientHost;

/**
 *  Stops the transaction
 *
 *  @return YES on success
 */
- (BOOL) endTransaction;


#pragma mark - Step methods
/**
 *  Starts a new transaction step
 *
 *  @return newly created trace step
 */
- (SUPE2ETraceStep*) createStep;

/**
 *  Stops the trace step
 *
 *  @param step_in step to be ended
 *
 *  @return YES on success
 */
- (BOOL) endStep:(SUPE2ETraceStep*)step_in;


#pragma mark - Request methods

/**
 *  Creates a new step request
 *
 *  @return created trace request
 */
- (SUPE2ETraceRequest*) createRequest;

/**
 *  Stops the trace request
 *
 *  @param request_in request to be ended
 *
 *  @return YES on success
 */
- (BOOL) endRequest:(SUPE2ETraceRequest*)request_in;


#pragma mark - Business Transaction XML generation and upload
/**
 *  Retrieves the generated Business Transaction XML.
 *
 *  @return BTX (as string)
 */
- (NSString*) getXML;

/**
 *  Uploads the generated BTX to provided server URL and returns the response status code
 *  Currently the upload link is composed as following: <baseURL>/E2EClientTraceUploadW/UploadForm.jsp
 *
 *  @param toBaseURL URL where to upload the BTX
 *
 *  @return Response status code; 200 (HTTP OK) means success
 */
- (NSUInteger) sendXML:(NSURL*)toBaseURL;


#pragma mark - Step / request accessors
// APIs in this section are candidates for redesign or removal
// TODO: check whether these methods can be removed; if not, API change + refactor required
/**
 *  Returns a dictionary containing references to Step and Request Object for a given PassportHttpHeader
 *  If developers store the PassportHttpHeader with their own objects, they can retrieve the relevant Step and request object references later with PassportHeader as lookup parameter.
 *
 *  @param Passport_in <#Passport_in description#>
 *
 *  @return dictionary in the form @{ @"stepObj" : step, @"reqObj" : request }
 */
- (NSDictionary*) getStepAndRequestByPassportHeader:(NSString*)Passport_in;

// TODO: check whether this can be removed; if not, API change + refactor required
/**
 *  Returns a dictionary containing references to Step and Request Object for a given
 *  Key/Value pair within an SUPE2ETraceRequest object. If developers store the Value for a specific Request Key with their own objects they can retrieve the relevant Step and request object references later with the Key and Value as lookup parameter.
 *
 *  @param key_in   Key field in SUPE2ETraceRequest
 *  @param value_in Searchvalue for Key field in SUPE2ETraceRequest
 *
 *  @return dictionary in the form @{ @"stepObj" : step, @"reqObj" : request }
 */
- (NSDictionary*) getStepAndRequestForKey:(NSString*)key_in withSearchString:(NSString*)value_in;

// TODO: check whether this can be removed; if not, API change + refactor required
/**
 *  Sets custom search key to be set with a application specific value for later retrieval of the SUPE2ETraceRequest and SUPE2ETraceStep object reference.
 *
 *  @param theRequest_in <#theRequest_in description#>
 *  @param value_in      custom search key
 *
 *  @return <#return value description#>
 */
- (BOOL) setSearchKeyForRequest:(SUPE2ETraceRequest*)theRequest_in WithValue:(NSString*)value_in;

// TODO: check whether this can be removed; if not, API change + refactor required
/**
 *  Returns a dictionary containing references to Step and Request Object for a custom serach key
 *
 *  @param Value_in custom serach key set previously via setSearchKeyForRequest: WithValue:
 *
 *  @return  dictionary in the form @{ @"stepObj" : step, @"reqObj" : request }
 */
- (NSDictionary*) getStepAndRequestForSearchValue:(NSString*)value_in;

/**
 *  Updates the data for each request and step to form transaction step xml and append it to the business transaction xml
 *
 *  @param theRequest <#theRequest description#>
 *  @param value_in   step and tracerequest object value
 *  @param key_in     step and tracerequest object key
 *
 *  @return <#return value description#>
 */
- (BOOL) updateRequestElementWithValue:(SUPE2ETraceRequest*)theRequest :(NSString*)value_in :(NSString*)key_in;  DEPRECATED_ATTRIBUTE;

/**
 *  Updates the data for each request and step to form transaction step xml and append it to the business transaction xml
 *
 *  @param theRequest <#theRequest description#>
 *  @param value_in   step and tracerequest object value
 *  @param key_in     step and tracerequest object key
 *
 *  @return <#return value description#>
 */
- (BOOL) updateRequestElementWithValue:(SUPE2ETraceRequest*)theRequest value:(NSString*)value_in forKey:(NSString*)key_in;

/**
 *  Updates the data for each request and step to form transaction step xml and append it to the business transaction xml
 *
 *  @param request_in    <#request_in description#>
 *  @param dictionary_in Contains the references to step and traceRequest object with passportheader and co-relationID
 *
 *  @return <#return value description#>
 */
- (BOOL) updateRequestElementsInRequest:(SUPE2ETraceRequest*)request_in withDictionary:(NSDictionary*)dictionary_in;

@end
