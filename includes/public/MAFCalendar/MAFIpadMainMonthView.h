//
//  MAFIpadMainMonthView.h
//  MAFCalendar
//
//  Created by SpongeBob SquarePants on 1/11/13.
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFCalendarView.h"

/** The following events can be handled for IPad MonthView
*
* Callback method triggered when user selects a specific appointment.
* @param sender the respective calender view container
* @param app the selected appointment
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointment:(id<MAFAppointmentProtocol>)app;
*
*
 *Callback method triggered when user selects a specific appointment with long presss within the MAFCalendarView.
 *@param sender the respective calender view container
 *@param app the selected appointment
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointmentWithLongPressStart:(id<MAFAppointmentProtocol>)app;
*
*
 *Callback method triggered when user selects a specific appointment with long press within the MAFCalendarView.
 *@param sender the respective calender view container
 *@param app the selected appointment
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthAppointmentWithLongPressEnd:(id<MAFAppointmentProtocol>)app;
*
*
* Callback method triggered when user selects the more appointment label within the MAFCalendarView.
* @param sender the respective calender view container
* @param date The date of the appointments
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthMoreAppointmentsForDay:(NSDate*)date;
*
*
*
* Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
* @param sender the respective calender view container
* @param date The date of the corresponding day
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDay:(NSDate*)date;
*
*
 *Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
 *@param sender the respective calender view container
 *@param date The date of the corresponding day
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDayWithLongPressStart:(NSDate*)date;
*
*
*
* Callback method triggered when user selects the dayNumberLabel or the DayBox within the MAFCalendarView.
* @param sender the respective calender view container
* @param date The date of the corresponding day
 *-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthDayWithLongPressEnd:(NSDate*)date;
*
*
*
* Callback method triggered when user selects the WeekNumber Label on IPad MonthView
* @param sender the respective calender view container
* @param date The date of the corresponding week's first day
* @param endDate The date of the corresponding week's last day
*-(void)calendarView:(MAFCalendarView*)sender didSelectIPadMonthWeekStartingWithDate:(NSDate*)date endDate:(NSDate*)endDate;
*
*
*
*Callback method triggered when a dayBox will be renderes, user can get the instance and modify its appereance here and return
*the modified dayBoxView
*
*@param sender the respective calender view container
*@param date The date of the corresponding week's first day
*The following properties can be modified here:
*
*appointmentLabelColor;
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
*
*-(void)calendarView:(MAFCalendarView*)sender willRenderDayBox:(MAFIPadMonthDayBox*)dayBox;
*
 *
 *
 *
 *
*THE IPADMONTHVIEW CAN BE STYLED FROM XML FOR THE FOLLOWING STYLES:
 *
 *
 *OVERVIEW:
 *
 *CalendarMonthViewMonthdayTextLabel
 *CalendarMonthViewCurrentMonthdayTextLabel
 *CalendarMonthViewGutter
 *CalendarMonthViewCanvas
 *CalendarMonthViewWeekLabelFont
 *CalendarMonthViewWeekLabelHighlightColor
 *CalendarMonthViewCurrentMonthdayBoxNumberTextLabel
 *CalendarMonthViewCurrentMonthdayBoxAppointment
 *CalendarMonthViewCurrentMonthdayDecoratorBox
 *CalendarMonthViewMonthdayBoxNumberTextLabel
 *CalendarMonthViewMonthdayBoxAppointment
 *CalendarMonthViewMonthdayDecoratorBox
 *CalendarMonthViewCurrentDayBox
 *CalendarMonthViewDayBox
 *CalendarMonthViewWeekView
 *CalendarMonthViewTopHeader
 *CalendarMonthViewSelectedMonthdayBoxAppointment
 *CalendarMonthViewHorizontalShadowGradient
 *CalendarMonthViewVerticalShadowGradient
 *CalendarMonthViewLowerHeaderShadowGradient
 *CalendarMonthViewTopHeaderShadowGradient
 *
*
*
*
* DETAILS:
*
*"CalendarMonthViewMonthdayTextLabel" :
*The style for the text in the header (Daynames at top) :
*<Style TargetType="Control" Key="CalendarMonthViewMonthdayTextLabel" platform="ios">
*     <Setter Property="Foreground" Value="#bbbbbb"/>
*     <Setter Property="FontFamily" Value="Arial-BoldMT"/>
*     <Setter Property="FontSize" Value="15"/>
*     <Setter Property="Background" Value="#222222"/>
*</Style>
*
*
 *"CalendarMonthViewCurrentMonthdayTextLabel":
* The style for the text in the header for the current day (today):
* <Style Key="CalendarMonthViewCurrentMonthdayTextLabel" TargetType="Control" platform="ios">
*       <Setter Property="Foreground" Value="#332233"/>
*       <Setter Property="FontFamily" Value="Arial-BoldMT"/>
*       <Setter Property="FontSize" Value="15"/>
*       <Setter Property="Background" Value="#669933"/>
*</Style>
*
*
*"CalendarMonthViewGutter":
* The color of the IPadMonthview's contentheader and contentFooter
* <Style Key="CalendarMonthViewGutter" TargetType="Control" platform="ios">
*        <Setter Property="Background" Value="#335533"/>
* </Style>
*
*
* "CalendarMonthViewCanvas" :
* The background color of the IPadMonthView Content, including the gap between the dayBoxes.
 *<Style Key="CalendarMonthViewCanvas" TargetType="Control" platform="ios">
 *       <Setter Property="Background" Value="#000000"/>
 *</Style>
*
*
*  "CalendarMonthViewWeekLabelFont" :
* The font for the weeknumber label in the left side of the IPadMonthview.
* <Style Key="CalendarMonthViewWeekLabelFont" TargetType="Control" platform="ios">
*        <Setter Property="Foreground" Value="#000000"/>
*        <Setter Property="FontFamily" Value="Arial"/>
*        <Setter Property="FontSize" Value="12"/>
* </Style>
*
*
*
* "CalendarMonthViewWeekLabelHighlightColor":
* The font for the current weeknumber label in the left side of the IPadMonthview.
* <Style Key="CalendarMonthViewWeekLabelFont" TargetType="Control" platform="ios">
*        <Setter Property="Foreground" Value="#000000"/>
*        <Setter Property="FontFamily" Value="Arial"/>
*        <Setter Property="FontSize" Value="12"/>
* </Style>
 *
 *"CalendarMonthViewMonthdayBoxNumberTextLabel":
 *The style for the number of day in the daybox.
 *<Style Key="CalendarMonthViewMonthdayBoxNumberTextLabel" TargetType="Control" platform="ios">
  *      <Setter Property="Foreground" Value="#ffffff"/>
   *     <Setter Property="FontFamily" Value="Arial-BoldMT"/>
    *    <Setter Property="FontSize" Value="13"/>
 *</Style>
*
 *"CalendarMonthViewCurrentMonthdayBoxNumberTextLabel":
 *The style for the current (today) number of day in the daybox.
 *<Style Key="CalendarMonthViewCurrentMonthdayBoxNumberTextLabel" TargetType="Control" platform="ios">
  *      <Setter Property="Foreground" Value="#ffffff"/>
  *      <Setter Property="FontFamily" Value="Arial-BoldMT"/>
  *      <Setter Property="FontSize" Value="13"/>
 *</Style>
*
 * "CalendarMonthViewMonthdayBoxAppointment":
 *The style for the appointment withing a daybox.
 *<Style Key="CalendarMonthViewMonthdayBoxAppointment" TargetType="Control" platform="ios">
  *      <Setter Property="Foreground" Value="#66aa33"/>
   *     <Setter Property="FontFamily" Value="Arial"/>
   *     <Setter Property="FontSize" Value="12"/>
* </Style>
*
*
 *"CalendarMonthViewCurrentMonthdayBoxAppointment":
 *The style for the appointment withing the current (today) daybox.
 *<Style Key="CalendarMonthViewCurrentMonthdayBoxAppointment" TargetType="Control" platform="ios">
  *      <Setter Property="Foreground" Value="#66aa33"/>
  *     <Setter Property="FontFamily" Value="Arial"/>
  *      <Setter Property="FontSize" Value="12"/>
 *</Style>
*
 *"CalendarMonthViewSelectedMonthdayBoxAppointment":
* The style for the selected appointment withing a daybox.
* <Style Key="CalendarMonthViewSelectedMonthdayBoxAppointment" TargetType="Control" platform="ios">
*        <Setter Property="Foreground" Value="#66aa33"/>
*        <Setter Property="FontFamily" Value="Arial"/>
*        <Setter Property="FontSize" Value="12"/>
* </Style>
 *
 * "CalendarMonthViewMonthdayDecoratorBox":
* The color for the decorator box next to the appointments.
* <Style Key="CalendarMonthViewMonthdayDecoratorBox" TargetType="Control" platform="ios">
 *       <Setter Property="Background" Value="#66aa3377"/>
* </Style>
*
*
 *"CalendarMonthViewCurrentMonthdayDecoratorBox":
* The color for the decorator box next to the appointments in the current daybox.
* <Style Key="CalendarMonthViewCurrentMonthdayDecoratorBox" TargetType="Control" platform="ios">
*        <Setter Property="Background" Value="#66aa3377"/>
* </Style>
*
*
 *"CalendarMonthViewDayBox":
 *The style for the DayBox ( A day represented in a monthview is a daybox)
 *<Style Key="CalendarMonthViewDayBox" TargetType="Control" platform="ios">
 *       <Setter Property="Background" Value="#222222"/>
 *</Style>
*
*
 *"CalendarMonthViewCurrentDayBox":
 *The style for the current DayBox ( A day represented in a monthview is a daybox)
 *<Style Key="CalendarMonthViewCurrentDayBox" TargetType="Control" platform="ios">
  *      <Setter Property="Background" Value="#222222"/>
* </Style>
*
*
* "CalendarMonthViewWeekView"
* The style for the week view placed on the left side of the IPadMonthView.
* <Style Key="CalendarMonthViewWeekView" TargetType="Control" platform="ios">
 *       <Setter Property="Background" Value="#444444"/>
* </Style>
*
*
* "CalendarMonthViewTopHeader"
* The style for the top header showing the year.
* <Style Key="CalendarMonthViewTopHeader" TargetType="Control" platform="ios">
*        <Setter Property="Background" Value="#444444"/>
*        <Setter Property="Foreground" Value="#eeeeee"/>
*        <Setter Property="FontFamily" Value="Helvetica"/>
*        <Setter Property="FontSize" Value="16"/>
* </Style>
*
* "CalendarMonthViewHorizontalShadowGradient"
* The gradient for the horizontal shadow above the contentview.
* <Style Key="CalendarMonthViewHorizontalShadowGradient" TargetType="Control" platform="ios">
*    <Setter Property="Background">
*        <Setter.Value>
*            <LinearGradientBrush EndPoint="0.5,1" StartPoint="0.5,0">
*                <LinearGradientBrush.GradientStops>
*                    <GradientStop Color="#000000ff" Offset="0.0"/>
*                    <GradientStop Color="#00660000" Offset="1.0"/>
*                </LinearGradientBrush.GradientStops>
*            </LinearGradientBrush>
*        </Setter.Value>
*        </Setter>
* </Style>
*
*
* "CalendarMonthViewVerticalShadowGradient"
* The style for the gradient next to the weekView, the left side of the content view.
* <Style Key="CalendarMonthViewVerticalShadowGradient" TargetType="Control" platform="ios">
*    <Setter Property="Background">
*        <Setter.Value>
*            <LinearGradientBrush EndPoint="0.5,1" StartPoint="0.5,0">
*                <LinearGradientBrush.GradientStops>
*                    <GradientStop Color="#000000ff" Offset="0.0"/>
*                    <GradientStop Color="#00660000" Offset="1.0"/>
*                </LinearGradientBrush.GradientStops>
*            </LinearGradientBrush>
*        </Setter.Value>
*    </Setter>
* </Style>
*
* "CalendarMonthViewLowerHeaderShadowGradient":
* The style for the gradient just above the weekview, next to the dayview, that shows the days.
* <Style Key="CalendarMonthViewLowerHeaderShadowGradient" TargetType="Control" platform="ios">
*    <Setter Property="Background">
*        <Setter.Value>
*            <LinearGradientBrush EndPoint="0.5,1" StartPoint="0.5,0">
*                <LinearGradientBrush.GradientStops>
*                    <GradientStop Color="#000000ff" Offset="0.0"/>
*                    <GradientStop Color="#00660000" Offset="1.0"/>
*                </LinearGradientBrush.GradientStops>
*            </LinearGradientBrush>
*        </Setter.Value>
*    </Setter>
* </Style>
*
* "CalendarMonthViewTopHeaderShadowGradient":
* The sytle for the gradient at the top. Transition from top left corner to the header containing the year label.
* <Style Key="CalendarMonthViewTopHeaderShadowGradient" TargetType="Control" platform="ios">
*    <Setter Property="Background">
*        <Setter.Value>
*            <LinearGradientBrush EndPoint="0.5,1" StartPoint="0.5,0">
*                <LinearGradientBrush.GradientStops>
*                    <GradientStop Color="#000000ff" Offset="0.0"/>
*                    <GradientStop Color="#00660000" Offset="1.0"/>
*                </LinearGradientBrush.GradientStops>
*            </LinearGradientBrush>
*        </Setter.Value>
*    </Setter>
* </Style>
* 
*/

#define iPad    UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad
#define MAFMonthViewWeekBarWidth          50
#define MAFMonthViewDayBarHeight  81   // including 1px bottom margin line
#define MAFMonthViewSepBarHeight   0 
#define MAFMonthViewBoxWidth     138.8 
#define MAFMonthViewBoxHeight      180
#define MAFMonthViewOffset         22 
#define MAFMonthViewMonthWidth   MAFMonthViewBoxWidth*7
#define MAFMonthViewMonthHeight    MAFMonthViewBoxHeight*6+2*MAFMonthViewOffset+1

typedef enum
{
    MAFIpadMainMonthViewSegmentTop = 0,
    MAFIpadMainMonthViewSegmentMid,
    MAFIpadMainMonthViewSegmentBottom
} MAFIpadMainMonthViewSegment;

@interface MAFIpadMainMonthView : MAFCalendarView

-(id)initWithFrame:(CGRect)frame useShadows:(BOOL)shadows;

-(void)showNextMonth;

-(void)showPreviousMonth;
/** Tells whether the current day is displayed in month view. */
-(BOOL)showsCurrentDay;
/** 
 *  @brief      Triggers focusing(scroll to view) of top, mid or bottom area of month view. 
 *  @param      segment the segment the focus will be on.
 */
-(void)focusOnSegment:(MAFIpadMainMonthViewSegment)segment;

/**
 *  @brief      Places an appointment at given coordinates within month view. 
 *  @param      dayIdx Day of week with index
  *  @param      startWeek The week the appointmnet will be placed in.
  *  @param      weeks  The duration of the appointment
  *  @param      title  The title for the appointment
  *  @param      location The location for the appointment
 */
-(void)placeAppointmentAtDay:(int)dayIdx atWeek:(int)startWeek withDuration:(int)weeks withTitle:(NSString*)title andLocation:(NSString*)location;
/**
 *  @brief      Get a DayBox by an NSDate
 *  @param      date The date of the dayBox item we need.
 */
-(MAFIPadMonthDayBox*)getDayBoxForDate:(NSDate*)date;
 

//apply the setted styles
-(void)doMAFStyling;
//property holding the dayBoxArray of IPadMainMonthView
@property (retain, nonatomic) NSMutableArray* dayBoxArray;
/// property holding weather we want to use gradient shadows in the IPadMainMonthView
@property (assign) BOOL useShadows;
/// property holding array of dates (NSDate) for month days to be displayed in the month view
@property (retain,nonatomic) NSArray* monthDays;
/// property holding array of strings to be placed at week labels (beginning from bottom)
@property (retain,nonatomic) NSArray* weekLabels;
/// property holding flag whether current week indicator line shall be displayed
@property (assign) BOOL showWeekIndicator;
/// property holding font of month day label
@property (retain) UIFont*  monthdayLabelFont;
/// property holding font of month day number (within month) label
@property (retain) UIFont*  monthdayNumberLabelFont;
/// property holding background color of month day
@property (retain) UIColor* monthdayBackgroundColor;
/// property holding background color of month day (current day)
@property (retain) UIColor* currentMonthDayBackgroundColor;
/// property holding text color of month day label
@property (retain) UIColor* monthdayLabelTextColor;
/// property holding text color of month day number (within month) label
@property (retain) UIColor* monthdayNumberLabelTextColor;
/// property holding text color of month day label (current day)
@property (retain) UIColor* currentMonthDayLabelTextColor;
/// property holding text color of month day number (within month) label (current day)
@property (retain) UIColor* currentMonthDayNumberLabelTextColor;
/// property holding background color of month canvas
@property (retain) UIColor* monthBackgroundColor;
/// property holding background color of month gutter area (top/bottom)
@property (retain) UIColor* monthGutterBackgroundColor;
/// property holding font of full week label
@property (retain) UIFont* weekLabelFont;
/// property holding color of full week label
@property (retain) UIColor* weekLabelColor;
/// property holding font of highlighted full week label
@property (retain) UIColor* weekLabelHighlightColor;
/// property holding borderColor
@property (retain,nonatomic) UIColor* borderColor;
/// property holding the color of the box, next to an appointment in a dayBox
@property (retain) UIColor* decoratorBoxColor;
/// property holding the color of the box, next to the appointments in the current day box
@property (retain) UIColor* currentDecoratorBoxColor;
/// property holding the color of the dayboxes dateNumber label
@property (retain) UIColor* dayBoxNumberLabelColor;
/// property holding the font of the daybox's dateNumber
@property (retain) UIFont* dayBoxNumberLabelFont;
/// property holding the color of the datenumbeLabel in the Daybox
@property (retain) UIColor* currentDayBoxNumberLabelColor;
@property (retain) UIFont* currentDayBoxNumberLabelFont;

/// property holding the color of the appointment text label
@property (retain) UIColor* dayBoxTextLabelColor;
@property (retain) UIFont* dayBoxTextLabelFont;
/// property holding the color of the appointment text label for the current date
@property (retain) UIColor* currentDayBoxTextLabelColor;
@property (retain) UIFont* currentDayBoxTextLabelFont;

/// property holding the backgroundcolor for the dayBox.
@property (retain) UIColor* dayBoxColor;
/// property holding the color of the border for the daybox
@property (retain) UIColor* dayBoxBorderColor;

/// property holding the color of the current day's background color
@property (retain) UIColor* currentDayBoxColor;
/// property holding the current's day borderColor
@property (retain) UIColor* currentDayBoxBorderColor;
/// property holding the color for the view in the left side of the Monthview screen
@property (retain) UIColor* weekViewBackgroundColor;
///property holding the color for the IPadMonthview's top header color
@property (retain) UIColor* monthViewTopHeaderColor;
///property holding the font for the IPadMonthview's top header font
@property (retain) UIFont* monthViewTopHeaderFont;
///property holding the color for the IPadMonthview's top header's font
@property(retain) UIColor* monthViewTopHeaderFontColor;

///property holding the color for the selected appointment's foreground color
@property (retain) UIColor* selectedDayBoxTextLabelColor;
///property holding the font for the selected appointment's font
@property (retain) UIFont* selectedDayBoxTextLabelFont;
///property holding the backgroundcolor for the selected appointment in a daybox
@property (retain) UIColor* selectedDayBoxTextLabelBackgroundColor;

///property holding the startcolor of the lower vertical shadow
@property(retain) UIColor* verticalShadowStart;
///property holding the endcolor of the lower vertical shadow
@property(retain) UIColor* verticalShadowStop;
///property holding the startcolor of the central vertical shadow
@property(retain) UIColor* vertical2ShadowStart;
///property holding the endcolor of the central vertical shadow
@property(retain) UIColor* vertical2ShadowStop;
///property holding the endcolor of the top vertical shadow
@property(retain) UIColor* vertical3ShadowStart;
///property holding the endcolor of the top vertical shadow
@property(retain) UIColor* vertical3ShadowStop;
///property holding the startcolor of the horizontal shadow
@property(retain) UIColor* horizontalShadowStart;
///property holding the endcolor of the horizontal shadow
@property(retain) UIColor* horizontalShadowStop;

///properties holding the stylenames, that can be styled from xml
@property(retain,nonatomic) NSString* CalendarMonthViewHorizontalGradientStyle;
@property(retain,nonatomic) NSString* CalendarMonthViewVerticalGradientStyle;
@property(retain,nonatomic) NSString* CalendarMonthViewLowerHeaderVerticalGradientStyle;
@property(retain,nonatomic) NSString* CalendarMonthViewTopHeaderVerticalGradientStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewTopHeaderStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentDayBoxStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewDayBoxStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentMonthdayBoxNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewMonthdayBoxTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewSelectedMonthdayBoxTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentMonthdayBoxTextLabelStyle;
@property (retain,nonatomic) NSString*  CalendarMonthViewMonthdayNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentMonthdayNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewMonthdayTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentMonthdayTextLabelStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewWeekLabelFontStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewWeekLabelHighlightColorStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewMonthdayDecoratorBoxStyle;
@property (retain,nonatomic) NSString* CalendarMonthViewCurrentMonthdayDecoratorBoxStyle;
@property (retain,nonatomic) NSString*  CalendarMonthViewMonthdayBoxNumberTextLabelStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewGutterStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewCanvasStyle ;
@property (retain,nonatomic) NSString* CalendarMonthViewWeekViewStyle ;



@end
