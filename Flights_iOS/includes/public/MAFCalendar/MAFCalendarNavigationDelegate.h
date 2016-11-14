//
//  MAFCalendarNavigationDelegate.h
//  MAFCalendar
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MAFCalendarView;

@protocol MAFCalendarNavigationDelegate <NSObject>

@optional


/**
 Callback method triggered when te user will change to a specific day within the MAFCalendarView.
 
 @param sender the respective calendar view container
 @param day the selected day
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeToDay:(NSDate*)day;


/**
 Callback method triggered when user changes to  a specific day within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param day the selected day
 */
-(void)calendarView:(MAFCalendarView*)sender didChangeToDay:(NSDate*)day;


/**
 Callback method triggered when te user will change to a specific week within the MAFCalendarView.
 
 @param sender the respective calendar view container
 @param day the selected day
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeToWeekStartingAtDay:(NSDate*)day;


/**
 Callback method triggered when user changes to  a specific week within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param day the selected day
 */
-(void)calendarView:(MAFCalendarView*)sender didChangeToWeekStartingAtDay:(NSDate*)day;


/**
 Callback method triggered when te user will change to a specific month within the MAFCalendarView.
 
 @param sender the respective calendar view container
 @param day the selected day
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeToMonthStartingAtDay:(NSDate*)day;


/**
 Callback method triggered when user changes to a specific month within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param day the selected day
 */
-(void)calendarView:(MAFCalendarView*)sender didChangeToMonthStartingAtDay:(NSDate*)day;


/**
 Callback method triggered when user selects a specific day within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param day the selected day
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectDay:(NSDate*)day;


/**
 Callback method triggered when user selects a day range within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param firstDay day the first selected day
 @param lastDay day the last selected day
 */
-(void)calendarView:(MAFCalendarView*)sender rangeSelectionChanging:(NSDate*)firstDay lastDay:(NSDate*)lastDay;

/**
 Callback method triggered when user selects a day range within the MAFCalendarView and the selection finished.
 
 @param sender the respective calender view container
 @param firstDay day the first selected day
 @param lastDay day the last selected day
 */
-(void)calendarView:(MAFCalendarView*)sender didRangeSelected:(NSDate*)firstDay lastDay:(NSDate*)lastDay;

/**
 Depreceted in 1.2
 please use willChangeToMonthStartingAtDay
 Callback method triggered when user will change to  a specific month within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param month the ne month [1,...,12]
 @param year the new year
 
 @return flag whether user is allowed to change to month
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeToMonth:(NSInteger)month andYear:(NSInteger)year DEPRECATED_ATTRIBUTE;


/**
 Depreceted in 1.2
 Use didChangeToMonthStartingAtDay
 Callback method triggered when user changes to  a specific month within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param month the selected month [1,...,12]
 @param year the selected year
 */
-(void)calendarView:(MAFCalendarView*)sender didChangeToMonth:(NSInteger)month andYear:(NSInteger)year DEPRECATED_ATTRIBUTE;



/**
 Depreceted in 1.2
 Please use didSelectDay
 Callback method triggered when user selects a specific day within the MAFCalendarView and additional information
 about the selected day wrapped in a MAFDayInfo struct.
 
 @param sender the respective calender view container
 @param day the selected day
 @param dayInfo information about the day
 
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectDay:(NSDate*)day withDayInfo:(MAFDayInfo)dayInfo DEPRECATED_ATTRIBUTE;


/**
 Depreceted in 1.2
 Please use didChangeToDay
 Callback method triggered when user selects a specific day within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param day the new day
 */
-(void)calendarView:(MAFCalendarView*)sender dayViewDidChangeToNewDay:(NSDate*)day DEPRECATED_ATTRIBUTE;


/**
 Deprecetad in 1.2
 Please use didSelectDay
 Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param date The date of the corresponding day
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDay:(NSDate*)date DEPRECATED_ATTRIBUTE;


/**
 Deprecetad in 1.2
 Please use didSelectWeek
 Callback method triggered when user selects the WeekNumber Label on IPad MonthView
 
 @param sender the respective calender view container
 @param date The date of the corresponding week's first day
 @param endDate The date of the corresponding week's last day
 
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthWeekStartingWithDate:(NSDate*)date endDate:(NSDate*)endDate DEPRECATED_ATTRIBUTE;


/**
 Deprecetad in 1.2
 Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param date The date of the corresponding day
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDayWithLongPressStart:(NSDate*)date DEPRECATED_ATTRIBUTE;


/**
 Deprecetad in 1.2
 Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param date The date of the corresponding day
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDayWithLongPressEnd:(NSDate*)date DEPRECATED_ATTRIBUTE;


@end
