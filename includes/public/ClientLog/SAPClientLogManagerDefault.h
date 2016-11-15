//
//  SAPClientLogManager.h
//  ClientLog
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SAPClientLogManager.h"

@protocol SAPClientLogManager;

#pragma mark - Default implementation

@interface SAPClientLogManager : NSObject<SAPClientLogManager>

@property (retain) NSRecursiveLock *dbLock;
@property (nonatomic, strong, setter = aRootContextId:) 	NSString* rootContextId;

@end

