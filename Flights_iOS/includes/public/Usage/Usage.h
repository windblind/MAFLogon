//
//  ODataUsage.h
//  ODataUsage
//


#import <Foundation/Foundation.h>
#import "Timer.h"
#import "HttpConversationManager.h"


/**
 * The purpose of the Client Usage Collection feature is to enable customer administrators to view and generate
 * reports on application usage KPI's, across dimensions of device type & version, operating system type &
 * version,and sdk type & version. This class provides the main interface of the Usage library. The Usage feature
 * only supports Hana Mobile Server for now.
 *
 * Dependencies: HTTPConversation library
 *
 * Example to configure HTTPConversationManager:
 * 
 *  //instantiate manager object
 *  HttpConversationManager* manager = [[HttpConversationManager alloc] init];
 *
 *  //configurate with a CommonAuthenticationConfigurator which can handle most authentication processes
 *  //the CommonAuthenticationConfigurator can be found in the HTTPConvAuthFlows library
 *  CommonAuthenticationConfigurator* customConfigurator = [[CommonAuthenticationConfigurator alloc] init];
 *  [customConfigurator configureManager:manager];
 *
 * Example to initialize Usage library:
 * 
 *  //Create the URL to the HANA Mobile server
 *  NSString* urlForRequest = [NSString stringWithFormat:@"%@://%@:%@/clientusage", protocol, host, port];
 *
 *  //Call init method with encripytion key if you want to store your local data encrypted:
 *  [Usage initUsageWithURL:[NSURL URLWithString:urlForRequest] httpConversationManager:manager dataEncryptionKey:encrKey ]
 *
 *  //Or without the encryption key
 *  [Usage initUsageWithURL:[NSURL URLWithString:urlForRequest] httpConversationManager:manager]
 *
 * Example to use Timers:
 *  //start Timer with key:
 *  [Usage timeStart:@"MasterViewController"];
 *
 *  //stop and persist the previous timer:
 *  [Usage timeEnd:@"MasterViewController"];
 *
 *  //stop Timer with key and additional information
 *  NSMutableDictionary* info = [[NSMutableDictionary alloc]init];
 *  [info setValue.... forKey.... ];
 *  [Usage timeEnd:@"DetailViewController" info:info type:@"customTimer"]
 *
 */
@interface Usage : NSObject

/**
 *  Initialize the Usage library, read the persisted entries, create the database tables if it's not exists, start the current application session.
 *  Need to call first by the application
 *  @param url     upload URL; see example
 *  @param httpConversationManager  manager to use during upload; see example to configurate
 */
+(void)initUsageWithURL:(NSURL*)url httpConversationManager:(HttpConversationManager*)httpConversationManager;

/**
 *  Initialize the Usage library, read the persisted entries, create the database tables if it's not exists,encrypt it with the given key, start the current application session.
 *  Need to call first by the application
 *  @param url     upload URL
 *  @param httpConversationManager     manager to use during upload
 *  @param dataEncryptionKey     encryption key 
 */
+(void)initUsageWithURL:(NSURL*)url httpConversationManager:(HttpConversationManager*)httpConversationManager dataEncryptionKey:(NSString*)key;

/**
 *  Start a timer with and stores in memory with the given key. The timer is handled by the Usage library. To stop the timer call [Usage timeEnd:key] with the same key.
 *  If the key is nil, no Timer will be started. 
 *  If the key is already used the pervious timer will be overwritten. If you need handle Timers with the same key please use the (Timer*)makeTimer:key API
 *  @param key     Key to identify the timer
 */
+(void)timeStart:(NSString *)key;

/**
 *   Stops the timer started with API call [Usage timeStart:key] and persisited the result record into a database
 *   @param key     Key to identify the timer
 */
+(void)timeEnd:(NSString *)key;

/**
 *   Stops the timer started with API call [Usage timeStart:key] and persisited the result record into a database
 *   @param key     Key to identify the timer
 *   @param info    Dictionary which conatins key-value information about the given timer.Key-value should be NSString. The key names 'start' and 'duration' are protected. Any key with these protected names will be ignored.
 */
+(void)timeEnd:(NSString *)key info:(NSDictionary *)info;

/**
 *   Stops the timer started with API call [Usage timeStart:key] and persisited the result record into a database
 *   @param key     Key to identify the timer
 *   @param info    Dictionary which conatins key-value information about the given timer. Key-value should be NSString. The key names 'start' and 'duration' are protected. Any key with these protected names will be ignored.
 *   @param type    Type of the given timer
 */
+(void)timeEnd:(NSString *)key info:(NSDictionary *)info type:(NSString *)type;

/**
 *  Starts a timer with the given key and returns the Timer instance. To stop a Timer use [Usage stopTimer:timer] API. Usage library will not keep reference to the returned Timer.
 *  @param key     Key to identify the timer. Can be nil.
 */
+(Timer*)makeTimer:(NSString*)key;

/**
 *  Stops and persists the given Timer. Can be used to timers made by [Usage makeTimer:key] API. 
 *  @param timer     Given timer to be stoped and persisted.
 */
+(void)stopTimer:(Timer *)timer;

/**
 *  Stops and persists the given Timer. Can be used to timers made by [Usage makeTimer:key] API.
 *  @param timer   Given timer to be stoped and persisted.
 *  @param info    Dictionary which conatins key-value information about the given timer. Key-value should be NSString. The key names 'start' and 'duration' are protected. Any key with these protected names will be ignored.
 */
+(void)stopTimer:(Timer *)timer info:(NSDictionary *)info;

/**
 *  Stops and persists the given Timer. Can be used to timers made by [Usage makeTimer:key] API.
 *  @param timer   Given timer to be stoped and persisted.
 *  @param info    Dictionary which contains key-value information about the given timer. Key-value should be NSString. The key names 'start' and 'duration' are protected. Any key with these protected names will be ignored.
 *  @param type    Type of the given timer
 */
+(void)stopTimer:(Timer *)timer info:(NSDictionary *)info type:(NSString *)type;

/**
 *  Create an usage record with the given key and persisted into a database
 *  @param key     Key to identify the usage log entry
 */
+(void)log:(NSString *)key;

/**
 *  Create an usage record with the given key and info and persisted into a database
 *  @param key     Key to identify the usage log entry
 *  @param info    Dictionary which contains key-value information about the given usage log
 */
+(void)log:(NSString *)key info:(NSDictionary *)info;

/**
 *  Create an usage record with the given key, info, and type and persisted into a database
 *  @param key     Key to identify the usage log entry
 *  @param info    Dictionary which contains key-value information about the given usage log
 *  @param type    Type of the given usage log
 */
+(void)log:(NSString *)key info:(NSDictionary *)info type:(NSString *)type;

/**
 *Sets how many days Usage waits before trying to send data on 3G.
 *@param count      The count of days to wait
 *@return   YES if set was successfull, NO otherwise
 */
+(BOOL)setLeftoutDaysCount:(NSInteger)count;


@end
