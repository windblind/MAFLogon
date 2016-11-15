//
//  Timer.h
//  


#import <Foundation/Foundation.h>
/**
 * Timer object to measure events. Do not instantiate, please use the Usage APIs:
 *
 * Example to handle Timer object:
 *  //get a Timer with instance:
 *  Timer* timer = [Usage makeTimer:@"MasterViewController"];
 *
 *  //stop and persist the p:
 *  [Usage stopTimer:timer];
 *
 *  //stop Timer with key and additional information
 *  NSMutableDictionary* info = [[NSMutableDictionary alloc]init];
 *  [info setValue.... forKey.... ];
 *  [Usage stopTimer:timer info:info type:@"customTimer"];
 *
 *
*/
@interface Timer : NSObject

/**
 * Duration will be measured when timer is stoped
 */
@property (nonatomic, retain) NSNumber * duration;

/**
 * Timestamp of the start date
 */
@property (nonatomic, retain) NSDate * start;

/**
 * Key of the Timer
 */
@property (nonatomic, retain) NSString * keyName;

/**
 * Start the timer
 */
-(void)startTimer;

/**
 * Stop the timer
 */
-(void)stopTimer;

@end
