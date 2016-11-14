//
//  MAFDayHeaderView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/20/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MAFListCalendarView.h"

/**
 @class MAFListCalendarHeaderView
 
 @brief Class responsible for rendering MAFListCalendarView headers with day details.
 
 This class is reponsible for rendering the headers of any MAFListCalendarView containing
 the day of week and date.
 
 @author Marc Roettig (external)
 
*/
@interface MAFListCalendarHeaderView : UIView
{
@private
    UILabel* dayOfWeekLabel;
    UILabel* dateLabel;
}

/// property holding parent table
@property (assign,nonatomic) MAFListCalendarView* parentTable;

/// property holding date of header view
@property (retain, nonatomic) NSDate*  date;
@property (assign, nonatomic) UIColor* headerTextColor;
@property (assign, nonatomic) UIFont*  headerFont;
@property (assign, nonatomic) UIColor* headerTextShadowColor;
@property (assign, nonatomic) UIColor* headerTextColorCurrentDay;
@property (assign, nonatomic) UIColor* headerTextShadowColorCurrentDay;
@property (assign, nonatomic) float    headerAlpha;
@property (assign, nonatomic) float    hourFieldWidth;
@property (retain, nonatomic) NSArray* headerBackgroundGradientCurrentDay;
@property (retain, nonatomic) NSArray* headerBackgroundGradient;


/**
 Initializer.
 
 @param frame frame of the view
 @param date the day to be represented as a date object
*/
-(id)initWithFrame:(CGRect)frame withDate:(NSDate*)date;

@end
