//
//  CacheVersion.h
//
//  Copyright (c) 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CacheVersion : NSObject

/**
 Retrieves the group ID of the library
 @remark generated on the build server
 */
+(NSString*)group;

/**
 Retrieves the artifect ID of the library
 @remark generated on the build server
 */
+(NSString*)artifact;

/**
 Retrieves the version number of the library
 @remark generated on the build server
 */
+(NSString*)version;

/**
 Retrieves the build time of the library
 @remark generated on the build server
 */
+(NSString*)buildTime;

/**
 Retrieves the git commitID of the last pushed change
 @remark generated on the build server
 */
+(NSString*)gitCommit;

/**
 Retrieves the git branch name
 @remark generated on the build server
 */
+(NSString*)gitBranch;

/**
 Retrieves the group ID and artifect ID and version number of the library
 @remark generated on the build server
 */
+(NSString*)versionAll;

@end