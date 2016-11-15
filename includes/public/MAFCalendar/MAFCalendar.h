//
//  MAFCalendar.h
//  CalendarControl
//
//  Created by Roettig, Marc (external) on 3/22/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 @class MAFCalendar
 @brief Class for calendars holding ID, name and colors.
 
 @author Marc Roettig (external)
*/
@interface MAFCalendar : NSObject

/// property holding unique ID of calendar
@property (retain,nonatomic) NSString* ID;
/// property holding title/name of calendar
@property (retain,nonatomic) NSString* name;
/// property holding color of calendar
@property (retain,nonatomic) UIColor*  color;
/// property holding border color of calendar
@property (retain,nonatomic) UIColor*  bordercolor;

@end
