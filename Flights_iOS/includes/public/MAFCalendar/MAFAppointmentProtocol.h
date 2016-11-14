//
//  Appointment.h
//  CalendarPlay
//
//  Created by Roettig, Marc (external) on 3/14/12.
//  Copyright (c) 2012 SAP AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAFCalendar.h"
#import "MAFAppointmentDelegate.h"


/**
 Enum holding the different appointment repeat types.
*/
typedef enum
{
    MAFAppointmentProtocolRepeatNone = 0,
    MAFAppointmentProtocolRepeatDaily,
    MAFAppointmentProtocolRepeatWeekly,
    MAFAppointmentProtocolRepeatBiWeekly,
    MAFAppointmentProtocolRepeatMonthly
} MAFAppointmentProtocolRepeatType;

/**
 Enum holding the different appointment alert types.
 */
typedef enum
{
    MAFAppointmentProtocolAlertNone = 0,
    MAFAppointmentProtocolAlert5Min,
    MAFAppointmentProtocolAlert15Min,
    MAFAppointmentProtocolAlert30Min,
    MAFAppointmentProtocolAlert1H,
    MAFAppointmentProtocolAlert2H,
    MAFAppointmentProtocolAlert1D,
    MAFAppointmentProtocolAlert2D,
    MAFAppointmentProtocolAlertOnTime,
} MAFAppointmentProtocolAlertType;



/**
 @brief Protocol declaring relevant appointment properties an implementing class should have.
 
 @author Jan Muehlbauer (external), Marc Roettig (external)
 
*/
@protocol MAFAppointmentProtocol <NSObject>

/// property holding MAFAppointmentDelegate reference
@property (nonatomic, assign) id <MAFAppointmentDelegate> delegate;

/// property holding MAFAppointmentDataSource reference
@property (nonatomic, assign) id datasource;

/// property holding starting date of appointment
@property (nonatomic, retain) NSDate* startDate;

/// property holding ending date of appointment
@property (nonatomic, retain) NSDate* endDate;

/// property holding title of appointment
@property (nonatomic, retain) NSString* title;

/// property holding location where appointment will take place
@property (nonatomic, retain) NSString* location;

/// property holding free form notes for appointment
@property (nonatomic, retain) NSString* notes;

/// property holding associated calendar of appointment
@property (nonatomic, retain) MAFCalendar* calendar;

/// property holding whether appointment was an invitation
@property (assign) BOOL isInvitation;

/// property holding whether appointment is all day
@property (assign) BOOL isAllday;

/// property holding repeating type of event (i.e. daily)
@property (assign) MAFAppointmentProtocolRepeatType repeatType;

/// property holding alert type of event (i.e. 15 min before event)
@property (assign) MAFAppointmentProtocolAlertType alertType;

@end
