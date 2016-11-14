//
//  MAFAppointmentDelegate.h
//  MAFCalendar
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MAFAppointmentProtocol;
@class MAFCalendarView;

@protocol MAFAppointmentDelegate <NSObject>

@optional

/**
 Callback method triggered when user requests creation of an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app new appointment with startDate and endDate property
 */
-(id<MAFAppointmentProtocol>)calendarView:(MAFCalendarView*)sender newAppointmentRequested:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when user request changing an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the edited appointment
 */
-(void)calendarView:(MAFCalendarView*)sender changeAppointmentRequested:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when user will change an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the selected appointment
 @return is user allowed to select it
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeAppointment:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when user changed an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the edited appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didChangeAppointment:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when the user draggint the appointment within a MAFCalendarView
 
 @param sender the respective calendar view container
 @param app the edited appointment
 */
-(void)calendarView:(MAFCalendarView*)sender appointmentChanging:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when user selects a specific appointment within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the selected appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectAppointment:(id<MAFAppointmentProtocol>)app;


/**
 Callback method triggered when user selects the more appointment label within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param date The date of the appointments
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectHiddenAppointments:(NSArray*)apps ForDay:(NSDate*)date;


/**
 Deprecated in 1.2
 Please use didSelectHiddenAppointments:ForDay:
 Callback method triggered when user selects the more appointment label within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param date The date of the appointments
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthMoreAppointmentsForDay:(NSDate*)date DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use newAppointmentRequested
 Callback method triggered when user requests creation of an appointment within a MAFCalendarView.
 
 
 @param sender the respective calender view container
 @param startDate start date of appointment
 @param endDate end date of appointment
 */
-(id<MAFAppointmentProtocol>)calendarView:(MAFCalendarView*)sender requestsCreationOfAppointmentWithStartDate:(NSDate*)startDate andEndDate:(NSDate*)endDate DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 please use didChangeAppointment
 Callback method triggered when user finished editing of an appointment within a MAFCalendarView.
 
 @param app the edited appointment
 */
- (void) appointmentDidChange:(id<MAFAppointmentProtocol>)sender DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Callback method triggered when user deletes an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the appointment to delete
 */
-(void)calendarView:(MAFCalendarView*)sender didDeleteAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use changeAppointmentRequested
 Callback method triggered when user request editing an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the edited appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didRequestEditingAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 */
-(void)calendarView:(MAFCalendarView*)sender didRequestRemoveAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use willChangeAppointment
 Callback method triggered when user will change an appointment within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param appFrom the edited appointment (current state)
 @param appTo the edited appointment (new state)
 @return is user allowed to do that change
 */
-(BOOL)calendarView:(MAFCalendarView*)sender willChangeAppointment:(id<MAFAppointmentProtocol>)appFrom toAppointment:(id<MAFAppointmentProtocol>)appTo DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use didSelectAppointment
 Callback method triggered when user selects a specific appointment.
 
 @param sender the respective calender view container
 @param app the selected appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;

/**
 Deprecated in 1.2
 Callback method triggered when user selects a specific appointment with long presss within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the selected appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointmentWithLongPressStart:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Callback method triggered when user selects a specific appointment with long press within the MAFCalendarView.
 
 @param sender the respective calender view container
 @param app the selected appointment
 */
-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointmentWithLongPressEnd:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;

@end
