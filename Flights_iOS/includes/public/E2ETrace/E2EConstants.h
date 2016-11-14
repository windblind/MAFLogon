//
//  E2EConstants.h
//  E2ETrace
//
//  Copyright 2014 SAP AG. All rights reserved.
//

/**
 * Defines the Trace levels
 * The verbosity of the E2E trace can be set using these trace levels
 */
typedef NS_ENUM(NSUInteger, E_E2E_TRACELEVEL)
{
    TraceLevelUndefined = 0,  ///< value not defined, used upon initialization in E2ETraceSettings
	TraceLevelLow = 1,	///< Focus on response-time distribution analysis (how much time is spent on each server component or where is the bottleneck)
	TraceLevelMedium,	///< Focus on perfromance analysis; performance traces are triggered on server-side (e.g. Introscope transaction trace, ABAP trace, SQL traces, etc.)
	TraceLevelHigh,		///< Functional analysis - activation of detailed functional logging and tracing in SAP J2EE and ABAP system
	TraceLevelNone,     ///< Focus on client side analysis. No traces are triggered on erver side at all
};