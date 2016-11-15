//
//  MAFCalendarViewDataSource.h
//  MAFCalendar
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFAppointmentProtocol.h"

@class MAFCalendar;
@class MAFCalendarView;
@class MAFListCalendarView;
@class MAFListCalendarViewCell;
@class MAFMonthCalendarView;
@class MAFMonthCalendarItemView;

typedef struct
{
    NSInteger dayOfWeek;
    NSInteger dayOfMonth;
    NSInteger month;
    NSInteger year;
} MAFDayInfo DEPRECATED_ATTRIBUTE;

/**
 @brief Datasource protocol used by MAFCalendar views to acquire their data.
 
 Datasource protocol used by MAFCalendar views to acquire their data.
 
 */
@protocol MAFCalendarViewDataSource<NSObject>

/**
 This methods lets calendar view request all appointments scheduled for a given time range.
 
 @param sender the requesting MAFCalendarView
 @param start the start date of the range
 @param end the end date of the range
 
 @return array of id<MAFAppointmentProtocol> objects
 */
-(NSArray*)calendarView:(MAFCalendarView*)sender getAppointmentsFromStart:(NSDate*)start toEnd:(NSDate*)end;

@optional

/**
 Deprecated in 1.2
 Please use getAppointmentsFromStart:toEnd:
 This methods lets calendar view request all appointments from a given calendar scheduled for a given time range.
 
 @param sender the requesting MAFCalendarView
 @param start the start date of the range
 @param end the end date of the range
 @param calendar desired calendar
 
 @return array of id<MAFAppointmentProtocol> objects
 */
-(NSArray*)calendarView:(MAFCalendarView*)sender getAppointmentsFromStart:(NSDate*)start toEnd:(NSDate*)end fromCalendar:(MAFCalendar*)calendar DEPRECATED_ATTRIBUTE; 





@end

