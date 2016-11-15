// *****************************************************
// Copyright (c) 2013 SAP AG or an SAP affiliate company. All rights reserved.
// *****************************************************

#import <Foundation/Foundation.h>

@class HttpConversationManager;

/**
 * An Offline Store Options object contains the configuration details required
 * to open an offline store.
 *
 */
@interface SODataOfflineStoreOptions : NSObject

/**
 * An HTTP Conversation Manager to handle network authentication.
 * This is a required property.
 */
@property(atomic,strong)	HttpConversationManager * conversationManager;
/**
 * The service root of the OData Producer.
 * When the server is an instance of SMP or Hana Mobile Cloud this is the name of the application backend connector.
 * This is a required property.
 */
@property(atomic,copy)		NSString*		serviceRoot;
/**
 * A dictionary of defining requests.  
 * The keys (names) of the defining requests are arbitrary and are used when performing refreshes with subsets.
 * The values (requests) are defining request URLs.
 * This is a required property.
 *
 * A defining request is an OData read request that targets the OData endpoint associated with the offline store 
 * and retrieves a subset of the OData endpoint data. Multiple defining requests can be defined for each OData endpoint.
 * Defining requests are a subset of data from the OData Producer that is sent to the client, either during initialization 
 * of the offline store or during a refresh.
 * 
 * Note that defining requests become fixed for an offline store the first time it is opened.  
 *
 */
@property(atomic,readonly)	NSMutableDictionary*	definingRequests __attribute__((deprecated));
/**
 * An arbitrary name to identify this store.
 * This is an optional property. 
 * If omitted a default name will be chosen.
 */
@property(atomic,copy)		NSString*		storeName;
/**
 * A key to use to encrypt the local data store.
 * This is an optional property. 
 * WARNING: If this property is omitted the store will be created without 
 * encrypting the data on the device.
 *
 */
@property(atomic,copy)		NSString*		storeEncryptionKey;
/**
 * The host of the server.
 * This is a required property.
 */
@property(atomic,copy)		NSString*		host;
/**
 * The port of the server.
 * This is a required property.
 */
@property(atomic,assign)	NSInteger		port;
/**
 * The URL suffix path to the server.
 * Specify the suffix to add to the URL of each HTTP request sent to the server.
 * When connecting through a proxy or web server, the urlSuffix may be necessary to find the server.
 * This is an optional property. 
 */
@property(atomic,copy)		NSString*		urlSuffix;
/**
 * Additional advanced stream parameters.
 * This is an optional property. 
 */
@property(atomic,copy)		NSString*		extraStreamParms;
/**
 * A dictionary of custom headers to add to all http communications.
 * These are added to HTTP requests between the offline store and server
 * and to HTTP requests between the server and the backend OData Producer.
 * The keys are header names.
 * The values are header values.
 * This is an optional property. 
 */
@property(atomic,readonly)	NSMutableDictionary*	customHeaders;
/**
 * A dictionary of custom cookies to add to all http communications.
 * These are added to HTTP requests between the offline store and server
 * and to HTTP requests between the server and the backend OData Producer.
 * The keys are cookie names.
 * The values are cookie values.
 * This is an optional property. 
 */
@property(atomic,readonly)	NSMutableDictionary*	customCookies;
/**
 * Specifies whether to use HTTP or HTTPS to communicate with the server.
 * This is an optional property. 
 * The default is to use unencrypted HTTP.
 */
@property(atomic,assign)	bool			enableHttps;
/**
 * Specifies whether the backend OData Producer supports repeatable requests.
 *
 * Repeatable requests (or idempotent requests) is a feature of some OData Producers that ensures
 * OData requests are applied only once even if they are received multiple times.
 * This is useful in cases where OData responses may be lost due to intermittent network connectivity
 * and is required by the offline store in order to guarantee that requests are applied exactly once
 * to the backend OData Producer.
 */
@property(atomic,assign)	bool			enableRepeatableRequests;
/**
 * Specifies the maximum number of entities that can be returned in a single read request.
 *
 * Reading an entity set will return at most this many entities in its response payload.  
 * If the response is a partial set of entities then a "next link" to the next part of the response will be provided.
 */
@property(atomic,assign)	NSInteger		pageSize;
/**
 * Adds a new defining request.
 * A defining request is an OData read request that targets the OData endpoint associated with the offline store 
 * and retrieves a subset of the OData endpoint data. Multiple defining requests can be defined for each OData endpoint.
 * Defining requests are a subset of data from the OData Producer that is sent to the client, either during initialization 
 * of the offline store or during a refresh.
 * 
 * Note that defining requests become fixed for an offline store the first time it is opened.  
 *
 * @param name an arbitrary and unique name associated with the defining request.  The name is used to refresh subsets of defining requests.
 * @param url the URL of the GET request used to target the data to store offline.
 * @param retrieveStreams whether to retrieve and store any media streams associated with the data targeted by this defining request.
 *            This must be set to false if the URL does not target any media entities.
 *
 */
- (void) addDefiningRequestWithName:(NSString*)name
				url:(NSString*) url
		    retrieveStreams:(bool) retrieveStreams;


@end

