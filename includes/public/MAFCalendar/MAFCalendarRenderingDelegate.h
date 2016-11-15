//
//  MAFCalendarRenderingDelegate.h
//  MAFCalendar
//
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MAFAppointmentView;
@class MAFIPadMonthDayBox;

@protocol MAFCalendarRenderingDelegate <NSObject>

@optional


/**
 This method can be used by framework users to style the item views for IPadMonthView (MAFIpadMainMonthView), IPhoneMonthView (MAFMonthComboCalendarView) and ListCalendarView (MAFListCalendarView).
 
 @param sender the respective calender view container
 @param view the appointment view to be styled
 */
-(void)calendarView:(MAFCalendarView*)sender willRenderItem:(UIView*)item;


/**
 This method can be used by framework users to supply custom day item views for IPadMonthView (MAFIpadMainMonthView) and IPhoneMonthView (MAFMonthComboCalendarView).
 
 @param sender the calendar view requesting a item view
 @param day the day to be displayed
 @param rect the available size
 
 @return item view (will be resized to available size)
 */
-(UIView*)itemViewForCalendarView:(MAFCalendarView*)sender forDay:(NSDate*)day inRect:(CGRect)rect;


/**
 This method can be used by framework users to style the appointment views for dayView (MAFDayDetailView) and weekView (MAFLandscapeCalendarView).
 
 @param sender the respective calender view container
 @param appointment the appointment view to be styled
 */
-(void)calendarView:(MAFCalendarView*)sender willRenderAppointment:(MAFAppointmentView*)appointment;


/**
 This method can be used by framework users to supply custom appointment views for dayView (MAFDayDetailView) and weekView (MAFLandscapeCalendarView).
 
 @param sender the calendar view requesting a item view
 @param day the day to be displayed
 @param rect the available size
 
 @return appointment view (will be resized to available size)
 */
-(UIView*)appointmentViewForCalendarView:(MAFCalendarView*)sender forAppointment:(id<MAFAppointmentProtocol>)day forRect:(CGRect)rect;


/**
 This method can be used by framework users to style the header views for ListCalendarView (MAFListCalendarView) and weekView (MAFLandscapeCalendarView).
 
 @param sender the respective calender view container
 @param header the header view to be styled
 */
-(void)calendarView:(MAFCalendarView*)sender willRenderHeader:(UIView*)header;


/**
 This method can be used by framework users to supply custom header views for IPadMonthView (MAFIpadMainMonthView) weekView (MAFLandscapeCalendarView and ListCalendarView (MAFListCalendarView).
 
 @param sender the calendar view requesting a header view
 @param day the day to be displayed
 @param rect the available size
 
 @return header view (will be resized to available size)
 */
-(UIView*)headerViewForCalendarView:(MAFCalendarView*)sender forDay:(NSDate*)day forRect:(CGRect)rect;


/**
 This method can be used by framework users to supply custom tableViewCells for ListCalendarView (MAFListCalendarView).
 
 @param sender the calendar view requesting a tableViewCell
 @param app the appointment view to be displayed
 @param identifier the tableViewCell's reuseidentifier
 
 @return cell view
 */
-(UITableViewCell*)listAppointmentViewForCalendarView:(MAFListCalendarView*)sender forAppointment:(id<MAFAppointmentProtocol>)app withReuseIdentifier:(NSString*)identifier;

//-(void)calendarView:(MAFListCalendarView*)sender willRenderListAppointment:(id<MAFAppointmentProtocol>)app withReuseIdentifier:(NSString*)identifier;

/**
 Deprecated in 1.2
 Please use headerViewForCalendarView
 This method can be used by framework users to supply custom day header cells for week view (MAFLandscapeCalendarView).
 
 @param weekView the week calendar view requesting a item view
 @param dayInfo the day info about the day to be displayed in header cell
 @param size the available size
 
 @return header view (will be resized to available size)
 */
-(UIView*)weekCalendar:(MAFCalendarView*)weekView headerViewforDay:(MAFDayInfo)dayInfo withCanvasSize:(CGSize)size DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use appointmentViewForCalendarView
 This method can be used by framework users to supply custom client view for placed appointment views (MAFLandscapeCalendarView).
 
 @note client view will receive change events via MAFAppointmentViewClientDelegate
 
 @param weekView the week calendar view requesting a item view
 @param app the appointment represented by the appointment view
 
 @return client view
 */
-(UIView*)weekCalendar:(MAFCalendarView*)weekView appointmenViewClientforAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;

/**
 Deprecated in 1.2
 Please use appointmentViewForCalendarView
 This method can be used by framework users to supply custom client view for placed appointment views (MAFDayDetailView).
 
 @note client view will receive change events via MAFAppointmentViewClientDelegate
 
 @param dayView the day calendar view requesting a item view
 @param app the appointment represented by the appointment view
 
 @return client view
 */
-(UIView*)dayCalendar:(MAFCalendarView*)dayView appointmenViewClientforAppointment:(id<MAFAppointmentProtocol>)app DEPRECATED_ATTRIBUTE;

/**
 Deprecated in 1.2
 Callback method triggered when frwk allows styling of an appointment view within a MAFCalendarView.
 
 @param sender the respective calender view container
 @param view the appointment view to be styled
 */
-(void)calendarView:(MAFCalendarView*)sender requestsStylingForAppointmentView:(MAFAppointmentView*)view DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use willRenderItem
 * Callback method triggered when a dayBox will be renderes, user can get the instance and modify its appereance here and return
 *the modified dayBoxView
 *
 * @param sender the respective calender view container
 * @param dayBox The dayBox in the mainMonthView that will be rendered.
 *The following properties can be modified here:
 *
 * appointmentLabelColor;
 *appointmentLabelBackgroundColorSelected;
 *appointmentLabelColorCurrent;
 *appointmentLabelColorSelected;
 *appointmentLabelFont;
 *appointmentLabelFontCurrent;
 *appointmentLabelFontSelected;
 *backgroundColor;
 *backgroundColorCurrent;
 *dayBoxItemArray;
 *dayNumberColor;
 *dayNumberColorCurrent;
 *dayNumberFont;
 *dayNumberFontCurrent;
 *decoratorColor;
 *decoratorColorCurrent;
 *borderColor;
 *borderColorCurrent;
 */
-(void)calendarView:(MAFCalendarView*)sender willRenderIPadMonthDayBox:(MAFIPadMonthDayBox*)dayBox DEPRECATED_ATTRIBUTE;


/**
 Deprecated in 1.2
 Please use listAppointmentViewForCalendarView
 This method can be used by framework users to supply custom MAFListCalendarView cells.
 
 @param sender the cell-requesting list calendar view
 @param app the appointment to fill into the cell
 @param identifier the tables reuse identifier
 
 @return list cell
 */
-(MAFListCalendarViewCell*)calendarView:(MAFListCalendarView*)sender getListCellForAppointment:(id<MAFAppointmentProtocol>)app withReuseIdentifier:(NSString*)identifier DEPRECATED_ATTRIBUTE;

/**
 Deprecated in 1.2
 Please use willRenderItem
 This method can be used by framework users to supply custom MAFMonthCalendarItemViews.
 
 @param sender the calendar view requesting a item view
 @param day the day of the item view as NSDate
 
 @return month item view
 */
-(MAFMonthCalendarItemView*)calendarView:(MAFMonthCalendarView*)sender forDay:(NSDate*)day DEPRECATED_ATTRIBUTE;

/**
 Deprecated in 1.2
 Please use willRenderItem
 This method can be used by framework users to change a MAFMonthCalendarItemView before rendering
 
 @param sender the calendar view requesting a item view
 @param item  the view that is going to be rendered
 
 */
-(void)calendarView:(MAFMonthCalendarView*)sender willRenderCalendarItem:(MAFMonthCalendarItemView*)item DEPRECATED_ATTRIBUTE;

@end
