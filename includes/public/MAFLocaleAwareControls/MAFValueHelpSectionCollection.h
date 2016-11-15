//
//  MAFValueHelpSectionCollection.h
//  MAFMadiatorArchitectureTest
//
//  Created by Muehlbauer, Jan (external) on 3/5/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import "MAFValueHelpListCollection.h"
#import "MAFValueHelpCollection.h"

/**
 @class MAFValueHelpSectionCollection 
 
 @brief The MAFValueHelpSectionCollection is used to store a
 collection that is partitioned into several sections. 
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFValueHelpSectionCollection : NSObject <MAFValueHelpCollection>
{
    @private
        NSMutableArray* sections;
}

/**
 Adds a key-value pair to a section identified by its section title.
 
 @param keyValuePair the key-value pair
 @param section title of the section
*/
-(void)addKeyValuePair:(MAFKeyValuePair*)keyValuePair forSection:(NSString*)section;

@end
