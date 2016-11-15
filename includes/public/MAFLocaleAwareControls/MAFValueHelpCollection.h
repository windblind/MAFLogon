//
//  MAFValueHelpCollection.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 3/5/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @brief Generic interface for (sectioned) collections of key-value pairs.
 
 This protocol declares all methods offered by
 all concrete MAFValueHelpCollection classes.
 
 @author Jan Muehlbauer (external)
 
*/
@protocol MAFValueHelpCollection <NSObject>

/**
 Returns the number of sections stored in the collection
 
 @return number of sections
*/
- (NSInteger)numberOfSections;

/**
 Returns an array of key-value pairs for a section.
 
 @param index of the section
 
 @return array of key-value pairs
*/ 
- (NSArray*)keyValuePairsForSection:(NSInteger)section;

/**
 Returns the title for a section.
 
 @param index of the section
*/
- (NSString*)titleForSection:(NSInteger)section;

/**
 Returns the overall count of key-value pairs located in any section.
 
 */
- (NSUInteger) count;

@end
