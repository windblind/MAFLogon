//
//  MAFListCalendarViewCell.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/19/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFAppointmentProtocol.h"
#import "MAFListCalendarView.h"

@class MAFListCalendarSymbolView;
@class MAFHourLabel;

/**
 @class MAFListCalendarViewCell
 
 @brief displays appointements in any MAFListCalendarView
 
 This class is responsible for presenting an appointment to
 the user.
 
 @author Marc Roettig (external)
*/
@interface MAFListCalendarViewCell : UITableViewCell
{
        MAFListCalendarSymbolView*  accView;
        MAFHourLabel* mafHourLabel;
        UIView*  textView;
        UILabel* titleLabel;
        UILabel* locationLabel;
}


/// property holding reference to parent table (needed to query current style properties)
@property (assign,nonatomic) MAFListCalendarView* parentTable;
/// property holding currently displayed appointment
@property (assign, nonatomic) id<MAFAppointmentProtocol> appointment;
@property (assign, nonatomic) UIColor* cellBackgroundColor;
@property (assign, nonatomic) UIFont * hourFont;
@property (assign, nonatomic) UIColor* hourTextColor;
@property (assign, nonatomic) UIColor* hourPeriodColor;
@property (assign, nonatomic) UIFont * titleFont;
@property (assign, nonatomic) UIColor* titleTextColor;
@property (assign, nonatomic) UIFont * locationFont;
@property (assign, nonatomic) UIColor* locationTextColor;
@property (assign, nonatomic) float hourFieldHeight;
@property (assign, nonatomic) float hourFieldWidth;

/**
 The style method receives an appointment to be presented within the cell
 and gets called whenever the cell gets visible. The method body has to
 properly style all needed subviews and provide them with values.
 
 Note: The default implementation of this method styles the cells in a
       defined (Welter-conform) default style. Framework users can subclass
       the class and override the style method to customize cell designs.
    
 
 @param app object adhering to MAFAppointmentProtocol
*/

-(void)style:(id<MAFAppointmentProtocol>)app;

/**
 The method create the subViews of the cell. One can overwrite it to modify the sub views. 
 */

-(void)buildView;

/**
 The method layouts the views. Overwrite it to modify the layout.
 */

-(void)layout;

@end
