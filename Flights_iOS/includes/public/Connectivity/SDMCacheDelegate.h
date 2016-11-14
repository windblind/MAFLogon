//
//  SDMCacheDelegate.h
//  SDMConnectivity library
//
//  !!! Note that download cache functionality has been disabled due to security reasons;
//  Related properties and APIs have not been removed in order to prevent build issues
//
//  Created by Karoly Nyisztor on Apr 11, 2011
//  Copyright SAP AG 2011. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SDMRequesting;

/**
 * Consists of supported cache policies.
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
typedef enum ECachePolicy
{
	//!
	DefaultCachePolicy = 0,
    //! do not use the DownloadCache 
	IgnoreCachePolicy = 1,
	//! fetch only if cached content differs from server content
	ReloadIfDifferentCachePolicy = 2,
	//! fetch only when cache is empty
	OnlyLoadIfNotCachedCachePolicy = 3,
	//! fetch only when network errors occur
	UseCacheIfLoadFailsCachePolicy = 4
} CachePolicy;

/**
 * Consists of supported cache lifetime policies.
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
typedef enum ECacheStoragePolicy
{
	//! cache is persisted only for this session
	CacheForSessionDurationCacheStoragePolicy = 0,
	//! cache persists after the session expires
	CachePermanentlyCacheStoragePolicy = 1
} CacheStoragePolicy;

/**
 * @deprecated
 * Defines default DownloadCache delegate methods
 *
 * @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * Protocol to be adapted by client classes in order to achieve the DownloadCache functionality
 * @remark Clients might consider using the SDMDownloadCache rather than implementing a custom download cache
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
@protocol SDMCacheDelegate <NSObject>

@required

/**
 * Returns the cache policy to be used when requests have their cache policy set to DefaultCachePolicy.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (CachePolicy)defaultCachePolicy DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Removes cached data for a particular request.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (void)removeCachedDataForRequest:( id<SDMRequesting> )request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * Returns YES if the cache considers its cached response current for the request.
 * Returns NO if the data is not cached, or (for example) if the cached headers state the request has expired.
 * @param request object of Request class.
 */
- (BOOL)isCachedDataCurrentForRequest:(id<SDMRequesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Stores the response for the passed request in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * When a non-zero maxAge is passed, it should be used as the expiry time for the cached response.
 */
- (void)storeResponseForRequest:(id<SDMRequesting>)request maxAge:(NSTimeInterval)maxAge DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Returns an NSDictionary of cached headers for the passed request, if it is stored in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (NSDictionary *)cachedHeadersForRequest:(id<SDMRequesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Returns the cached body of a response for the passed request, if it is stored in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (NSData *)cachedResponseDataForRequest:(id<SDMRequesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Same as the above, but returns a path to the cached response body instead
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (NSString *)pathToCachedResponseDataForRequest:(id<SDMRequesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Clear cached data stored for the passed storage policy
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 * 
 */
- (void)clearCachedResponsesForStoragePolicy:(CacheStoragePolicy)cachePolicy DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

@end
