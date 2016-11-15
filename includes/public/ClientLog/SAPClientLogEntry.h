//
//  SAPClientLogEntry.h
//  ClientLog
//
//  Copyright (c) 2014 SAP. All rights reserved.
//

#import "SAPClientLogLevel.h"

#define kTERM @"#"

@interface SAPClientLogEntry : NSObject 

@property (nonatomic, strong) 	NSDate* dateTime;
@property (nonatomic, strong) 	NSTimeZone* timeZone;
@property (assign) 				E_CLIENT_LOG_LEVEL severity;
@property (nonatomic, strong) 	NSString* sourceName;
@property (nonatomic, strong) 	NSString* msgCode;
@property (nonatomic, strong) 	NSString* dcComponent;
@property (nonatomic, strong) 	NSString* guid;
@property (nonatomic, strong) 	NSString* correlationId;
@property (nonatomic, strong) 	NSString* application;
@property (nonatomic, strong) 	NSString* location;
@property (nonatomic, strong) 	NSString* user;
@property (nonatomic, strong) 	NSString* rootContextId;
@property (nonatomic, strong) 	NSString* transactionId;
@property (nonatomic, strong) 	NSString* message;

- (id)initWithMessage:(NSString *)message andLevel:(E_CLIENT_LOG_LEVEL)level andTimestamp:(NSDate *)timestamp;

@end
