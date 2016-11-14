//
//  MAFIPadMonthDayBox.h
//  MAFCalendar
//
//  Created by Kalmar, Marton Jozsef on 1/21/13.
//  Copyright (c) 2013 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFIPadMonthLandscapeMonthView.h"

@interface MAFIPadMonthDayBox : UIView

@property(retain,nonatomic) NSMutableArray* dayBoxItemArray;
@property(retain,nonatomic) NSDate* dateOfBox;
@property (retain,nonatomic) NSString* dayNumberString ;
@property (retain,nonatomic) NSArray* appointmentsForDay;
@property (retain,nonatomic) NSString*  CalendarMonthViewDayNumberTextLabelStyle;
@property (assign,nonatomic) MAFIPadMonthLandscapeMonthView* parent;
@property (assign,atomic) BOOL isToday;

@property (retain,nonatomic) UIColor* backgroundColor;
@property (retain,nonatomic) UIColor* backgroundColorCurrent;

@property (retain,nonatomic) UIColor* appointmentLabelColor;
@property (retain,nonatomic) UIColor* appointmentLabelColorCurrent;

@property (retain,nonatomic) UIColor* appointmentLabelColorSelected;
@property (retain,nonatomic) UIColor* appointmentLabelBackgroundColorSelected;

@property (retain,nonatomic) UIFont*   appointmentLabelFont;
@property (retain,nonatomic) UIFont*   appointmentLabelFontCurrent;
@property (retain,nonatomic) UIFont*   appointmentLabelFontSelected;

@property (retain,nonatomic) UIColor* dayNumberColor;
@property (retain,nonatomic) UIColor* dayNumberColorCurrent;

@property (retain,nonatomic) UIFont* dayNumberFont;
@property (retain,nonatomic) UIFont* dayNumberFontCurrent;

@property (retain,nonatomic) UIColor* decoratorColor;
@property (retain,nonatomic) UIColor* decoratorColorCurrent;

@property (retain,nonatomic) UIColor* borderColor;
@property (retain,nonatomic) UIColor* borderColorCurrent;

-(id)initWithFrame:(CGRect)frame
          andTitle:(NSString*)title
   andAppointments:(NSArray*)apps
           isToday:(BOOL)isToday
        withParent:(MAFIPadMonthLandscapeMonthView*)view
withDate:(NSDate*)date
;

-(void)display;

@end





