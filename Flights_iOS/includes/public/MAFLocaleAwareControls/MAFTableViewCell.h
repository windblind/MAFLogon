//
//  MAFTableViewCell.h
//  MAFLocaleAwareControls
//
//  Created by Muehlbauer, Jan (external) on 3/8/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFValueHelpAccessor.h"
#import "MAFStyling.h"

/**
 @class MAFTableViewCell
 
 @brief Abstract base class for MAFTableViewCells.
 
 @author Jan Muehlbauer (external)
 
*/
@interface MAFTableViewCell : UITableViewCell <MAFValueHelpAccessor, MAFStyling>
{
	
}

/// property holding the preferred height of the cell
@property (nonatomic, readonly, getter=getPreferredCellHeight) float preferredCellHeight;

@end
