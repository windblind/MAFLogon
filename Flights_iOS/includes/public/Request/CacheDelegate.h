//
//  CacheDelegate.h
//  Request
//
//  !!! Note that download cache functionality has been disabled due to security reasons;
//  Related properties and APIs have not been removed in order to prevent build issues
//
//  Created by i061647 on 5/27/13.
//  Copyright (c) 2013 i061647. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol Requesting;

/**
 * Consists of supported cache policies.
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
typedef enum
{
	//!
	Default_CachePolicy = 0,
    //! do not use the DownloadCache
	Ignore_CachePolicy = 1,
	//! fetch only if cached content differs from server content
	ReloadIfDifferent_CachePolicy = 2,
	//! fetch only when cache is empty
	OnlyLoadIfNotCached_CachePolicy = 3,
	//! fetch only when network errors occur
	UseCacheIfLoadFails_CachePolicy = 4
} ECachePolicy;

/**
 * Consists of supported cache lifetime policies.
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
typedef enum
{
	//! cache is persisted only for this session
	CacheForSessionDuration_CacheStoragePolicy = 0,
	//! cache persists after the session expires
	CachePermanently_CacheStoragePolicy = 1
} ECacheStoragePolicy;

/**
 * @brief Defines default DownloadCache delegate methods.
 * @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 * This protocol should be adapted by client classes to use the DownloadCache functionality.
 * @remark Clients might consider using the DownloadCache rather than implementing a custom download cache.
 */
DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons")
@protocol CacheDelegate <NSObject>

@required

/**
 * Returns the cache policy to be used when requests have their cache policy set to DefaultCachePolicy.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 */
- (ECachePolicy)defaultCachePolicy DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Removes cached data for a particular request.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * @param request object of Request class.
 * @example
 * <pre>
 *  [cacheDelegate removeCachedDataForRequest:request];
 * </pre>
 */
- (void)removeCachedDataForRequest:( id<Requesting> )request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * Returns YES if the cache considers its cached response current for the request.
 * Returns NO if the data is not cached, or (for example) if the cached headers state the request has expired.
 * @param request object of Request class.
 * @example
 * <pre>
 *  [cacheDelegate isCachedDataCurrentForRequest:request];
 * </pre>
 */
- (BOOL)isCachedDataCurrentForRequest:(id<Requesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Stores the response for the passed request in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * When a non-zero maxAge is passed, it should be used as the expiry time for the cached response.
 * @param request object of Request class.
 * @param maxAge object of NSTimeInterval class.
 * @example
 * <pre>
 *  [cacheDelegate storeResponseForRequest:request maxAge:5];
 * </pre>
 */
- (void)storeResponseForRequest:(id<Requesting>)request maxAge:(NSTimeInterval)maxAge DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Returns an NSDictionary of cached headers for the passed request, if it is stored in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * @param request object of Request class.
 * @return Returns object of NSDictionary class.
 * @example
 * <pre>
 *  NSDictionary *headers = [cacheDelegate cachedHeadersForRequest:request];
 * </pre>
 */
- (NSDictionary *)cachedHeadersForRequest:(id<Requesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Returns the cached body of a response for the passed request, if it is stored in the cache.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * @param request object of Request class.
 * @return Returns object of NSData class.
 * @example
 * <pre>
 *  NSData *response = [cacheDelegate cachedResponseDataForRequest:request];
 * </pre>
 */
- (NSData *)cachedResponseDataForRequest:(id<Requesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Returns a path to the cached response body.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * @param request object of Request class.
 * @return Returns object of NSString class.
 * @example
 * <pre>
 *  NSString *path = [cacheDelegate pathToCachedResponseDataForRequest:request];
 * </pre>
 */
- (NSString *)pathToCachedResponseDataForRequest:(id<Requesting>)request DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");

/**
 * Clears cached data stored for the passed storage policy.
 *
 *  @warning Note that download cache functionality has been disabled due to security reasons; the related properties and APIs have not been removed in order to prevent build issues
 *
 * @param cachePolicy ECacheStoragePolicy enum value.
 * @example
 * <pre>
 *  [cacheDelegate clearCachedResponsesForStoragePolicy:CachePermanently_CacheStoragePolicy];
 * </pre>
 */
- (void)clearCachedResponsesForStoragePolicy:(ECacheStoragePolicy)cachePolicy DEPRECATED_MSG_ATTRIBUTE("Download cache functionality has been disabled due to security reasons");
@end

