//
//  MAFDayCalendarView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/19/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFCalendarView.h"

/**
    @class MAFListCalendarView
 
    @brief List-like view on appointments stored within a calendar.
 
    A class that displays a special calendar view presenting all (filtered)
    appointments in a list like fashion. 
 
    MAFListCalendarViewCell, MAFListCalendarHeaderView
 
    @author Marc Roettig (external)
*/
@interface MAFListCalendarView : MAFCalendarView <UITableViewDataSource,UITableViewDelegate>
{
    @private
        UITableView*         tv;
        NSMutableDictionary* dict;
        NSMutableArray*      arr;
        NSMutableDictionary* dateToSection;
        BOOL                 hasData;
}

/// property for changing alpha value of header area
@property (assign, nonatomic) float    headerAlpha;
/// property for changing font of date header text 
@property (retain, nonatomic) UIFont*  headerFont;
/// property for changing date header text color
@property (retain, nonatomic) UIColor* headerTextColor;
/// property for changing date header text color current day
@property (retain, nonatomic) UIColor* headerTextColorCurrentDay;
/// property for changing date header text color
@property (retain, nonatomic) UIColor* headerTextShadowColor;
/// property for changing date header text color current day
@property (retain, nonatomic) UIColor* headerTextShadowColorCurrentDay;
/// property for changing date header background gradient
@property (retain, nonatomic) NSArray* headerBackgroundGradient;
/// property for changing date header background gradient (current day)
@property (retain, nonatomic) NSArray* headerBackgroundGradientCurrentDay;

/// property for changing font of appointment cell text
@property (retain, nonatomic) UIFont*  hourFont;
/// property for changing appointment cell text color
@property (retain, nonatomic) UIColor* hourTextColor;
/// property for changing appointment cell text color
@property (retain, nonatomic) UIColor* hourPeriodColor;
/// property for changing font of appointment cell text
@property (retain, nonatomic) UIFont*  titleFont;
/// property for changing appointment cell text color
@property (retain, nonatomic) UIColor* titleTextColor;
/// property for changing font of appointment cell text
@property (retain, nonatomic) UIFont*  locationFont;
/// property for changing appointment cell text color
@property (retain, nonatomic) UIColor* locationTextColor;

/// property for changing appointment cell overall backgroundcolor
@property (retain, nonatomic) UIColor* cellBackgroundColor;
/// property holding color of cell separator line
@property (retain, nonatomic) UIColor* separatorColor;
/// property holding flag whether appointment shall be sorted after querying them from data source
@property (assign,nonatomic) BOOL doSorting;

@property (readonly, getter = getHourFieldWidth) float hourFieldWidth;
@property (readonly, getter = getHourFieldHeight) float hourFieldHeight;

/// property holding flag whether current day header shall be autoinserted when no app. scheduled for current day
@property (assign,nonatomic) BOOL autoInsertCurrentDay;
/// property holding flag whether header shall be hidden (i.e. for re-use in combo month view)
@property (assign,nonatomic) BOOL hideHeaders;

//settable styles
@property (retain, nonatomic) NSString* CalendarListViewHeaderTextStyle;
@property (retain, nonatomic) NSString* CalendarListViewHeaderTextCurrentDayStyle;
@property (retain, nonatomic) NSString* CalendarListViewHourTextLabelStyle;
@property (retain, nonatomic) NSString* CalendarListViewHourPeriodTextLabelStyle;
@property (retain, nonatomic) NSString* CalendarListViewAppointmentLocationTextLabelStyle;
@property (retain, nonatomic) NSString* CalendarListViewAppointmentTitleTextLabelStyle;
@property (retain, nonatomic) NSString* CalendarListViewAppointmentCellStyle;
@property (retain, nonatomic) NSString* CalendarListViewCellSeparatorStyle;

/**
 Initializer.
*/
-(id)init;

/**
 Designated initializer.
 
 @param frame a frame struct holding view's origin and dimension
*/
-(id)initWithFrame:(CGRect)frame;

/**
 Initializer.
 @param frame a frame struct holding view's origin and dimension
 @param rowHeight height of each row
*/
-(id)initWithFrame:(CGRect)frame rowHeight:(NSInteger)rowHeight;

/**
 Sets the range of dates using the specified start and end date.
 
 @param startDate the start date of the range
 @param endDate teh end date of the range
 
*/
-(void)setDateRangeToStart:(NSDate*)startDate andEnd:(NSDate*)endDate;

/**
 Brings the supplied day into focus.
 
 @param day date of the day
 */
-(void)focusDay:(NSDate*)day;

/**
 Brings the current day into focus.
 */
-(void)focusCurrentDay;

-(void)doMAFStyling;


@end
