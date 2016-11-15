//
//  Step.h
//  E2ETrace lib
//
//  Copyright 2014 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SUPE2ETraceStep : NSObject

@property (readonly, retain) NSMutableArray* messages;
@property (readonly, retain) NSMutableArray* events;

/**
 *  Creates a step in the context of the current transaction
 *
 *  @return step instance
 */
+ (SUPE2ETraceStep*) createStep;

/**
 *  Ends the current step
 *
 *  @return YES if ending the step was successful
 */
- (BOOL) endStep;

/**
 *  Retrieves the XML fragment for this very step
 *  This will be appended to the Business transaction XML
 *  @return Transaction Step XML as string
 */
- (NSString*) getXML;

/**
 *  Adds a UI related action
 */
- (void) addUIAction DEPRECATED_ATTRIBUTE;

@end
