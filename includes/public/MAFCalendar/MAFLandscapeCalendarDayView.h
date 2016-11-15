//
//  MAFLandscapeCalendarDayView.h
//  MAFCalendar
//
//  Created by Roettig, Marc (external) on 4/24/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFAppointmentView.h"
#import "MAFUILabel.h"

@class MAFLandscapeCalendarView;

/**
 @class MAFLandscapeCalendarDayView
 @brief View class displaying day header area on top of week view.
 
 @author Marc Roettig (external)
*/
@interface MAFLandscapeCalendarDayView : UIView<MAFAppointmentViewDelegate,UIGestureRecognizerDelegate>

@property (assign, nonatomic) MAFLandscapeCalendarView* parent;

/// property holding reference to parent week view
@property (retain,nonatomic) MAFUILabel* weekLabel;

@property (nonatomic, retain) UIFont*  weekdayNumberLabelFont;
@property (nonatomic, retain) UIFont*  weekdayLabelFont;
@property (nonatomic, retain) UIFont*  topHeaderFont;
@property (nonatomic, retain) UIColor* currentWeekDayNumberLabelTextColor;
@property (nonatomic, retain) UIColor* weekdayNumberLabelTextColor;
@property (nonatomic, retain) UIColor* topHeaderBackground;
@property (nonatomic, retain) UIColor* topHeaderFontColor;
@property (nonatomic, retain) UIColor* currentWeekDayLabelTextColor;
@property (nonatomic, retain) UIColor* weekdayLabelTextColor;
@property (nonatomic, retain) UIColor* weekFullHourSeparatorColor;
@property (nonatomic, retain) UIColor* currentWeekDayBackgroundColor;
@property (nonatomic, retain) UIColor* weekdayBackgroundColor;

//@property (nonatomic, retain) NSString* topHeaderText;

@property (nonatomic, retain) NSArray* weekDays;

/**
 Triggers reload of calendar data.
*/
-(void)reloadCalendarData;

@end
