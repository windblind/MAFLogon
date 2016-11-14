//
//  Transaction.h
//  E2ETrace lib
//
//  Copyright 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "E2EConstants.h"
#import "SAPExtendedPassport.h"


@interface SUPE2ETraceTransaction : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* id;
@property (nonatomic) NSUInteger status;
@property (nonatomic, strong) NSDictionary* attributes;
@property (nonatomic, strong) NSMutableArray* steps;

/**
 *  Creates a transaction with default attributes
 *
 *  @return transaction instance on success or nil
 */
+ (SUPE2ETraceTransaction*) createTransaction;

/**
 *  Creates a transaction using the input name and client host
 *
 *  @return transaction instance on success or nil
 */
+ (SUPE2ETraceTransaction*) createTransactionWithName:(NSString*)transactionName withClientHost:(NSString*)clientHost;

/**
 *  Clears transaction by resetting its name, id, associated steps and attributes
 *
 *  @return YES
 */
- (BOOL) endTransaction;

/**
 *  Builds and returns the Business Transaction XML
 *
 *  @return BTX as string
 */
- (NSString*) getXML;

@end
