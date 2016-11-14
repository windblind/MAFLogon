//
//  MAFMonthComboCalendarView.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 4/16/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAFListCalendarView.h"
#import "MAFMonthCalendarView.h"

@protocol MAFMonthComboCalendarViewDelegate
-(void)calendarView:(MAFMonthCalendarView*)calendar didSelectDay:(NSDate*)date;
@end

@class MAFMonthCalendarView;

@interface MAFMonthComboCalendarView : MAFCalendarView <MAFCalendarViewDelegate,MAFMonthComboCalendarViewDelegate>
{
    @private
    
    MAFListCalendarView* tv;
    //UIView* slaveView;
}

@property (retain,nonatomic) UIView<MAFMonthComboCalendarViewDelegate>* slaveView;
@property (retain,nonatomic) MAFMonthCalendarView* monthView;

-(id)initWithFrame:(CGRect)frame;

@end
