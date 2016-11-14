// Generated by SAP AFX Compiler (Tue Mar 10 11:04:25 CET 2015)

#ifndef SAP_XS_INTEGER_H
#define SAP_XS_INTEGER_H

#include "sap_xs_runtime.h"

@class XS_BigInteger;

@interface XS_BigInteger : NSObject
{
    @private xs_int my_big6;
    @private xs_int my_big5;
    @private xs_int my_big4;
    @private xs_int my_big3;
    @private xs_int my_big2;
    @private xs_int my_big1;
    @private xs_byte my_sign;
}
/* private */ - (id) init;
/* private */ + (void) initialize;
/* private */ + (XS_BigInteger*) ZERO;
/* private */ + (XS_BigInteger*) ONE;
/* private */ + (XS_BigInteger*) TWO;
/* public */ - (xs_int) sign;
/* public */ - (XS_BigInteger*) add :(XS_BigInteger*)p_y;
/* public */ - (XS_BigInteger*) subtract :(XS_BigInteger*)p_y;
/* public */ - (XS_BigInteger*) multiply :(XS_BigInteger*)p_y;
/* public */ - (XS_BigInteger*) divide :(XS_BigInteger*)p_y;
/* public */ - (XS_BigInteger*) remainder :(XS_BigInteger*)y;
/* public */ - (XS_BigInteger*) negate;
/* public */ - (XS_BigInteger*) abs;
/* public */ - (xs_int) compareTo :(XS_BigInteger*)p_y;
/* public */ - (xs_boolean) equals :(XS_BigInteger*)y;
/* public */ - (xs_boolean) notEqual :(XS_BigInteger*)y;
/* public */ - (xs_boolean) lessThan :(XS_BigInteger*)y;
/* public */ - (xs_boolean) lessEqual :(XS_BigInteger*)y;
/* public */ - (xs_boolean) greaterThan :(XS_BigInteger*)y;
/* public */ - (xs_boolean) greaterEqual :(XS_BigInteger*)y;
/* public */ - (NSString*) toString;
/* public */ + (XS_BigInteger*) fromByte :(xs_byte)value;
/* public */ + (XS_BigInteger*) fromShort :(xs_short)value;
/* public */ + (XS_BigInteger*) fromInt :(xs_int)value;
/* public */ + (XS_BigInteger*) fromLong :(xs_long)value;
/* public */ + (XS_BigInteger*) fromFloat :(xs_float)value;
/* public */ + (XS_BigInteger*) fromDouble :(xs_double)value;
/* public */ + (XS_BigInteger*) parse :(NSString*)text;
/* public */ - (xs_byte) byteValue;
/* public */ - (xs_short) shortValue;
/* public */ - (xs_int) intValue;
/* public */ - (xs_long) longValue;
/* public */ - (xs_float) floatValue;
/* public */ - (xs_double) doubleValue;
/* private */ - (xs_int) getDigit :(xs_int)i;
/* private */ - (void) setDigit :(xs_int)i :(xs_int)v;
/* private */ - (xs_int) compareAbs :(XS_BigInteger*)y;
/* private */ + (XS_BigInteger*) createZero;
/* private */ + (XS_BigInteger*) makeNumber :(xs_int)p_big6 :(xs_int)p_big5 :(xs_int)p_big4 :(xs_int)p_big3 :(xs_int)p_big2 :(xs_int)p_big1 :(xs_int)p_sign;
/* private */ + (XS_BigInteger*) lowNumber :(xs_int)p_big1;
/* private */ - (XS_BigInteger*) getDigits;
/* private */ - (xs_boolean) lowOnly;
/* private */ - (XS_BigInteger*) shiftLeft :(xs_int)n;
/* private */ + (xs_int) highDigit :(xs_long)x;
/* private */ + (xs_int) lowDigit :(xs_long)x;
/* private */ + (xs_long) digitMul :(xs_long)x :(xs_long)y;
/* private */ + (xs_int) digitDiv :(xs_long)x :(xs_long)y;
/* private */ + (xs_int) digitRem :(xs_long)x :(xs_long)y;
/* private */ - (XS_BigInteger*) withSign :(xs_int)p_sign;
/* private */ + (void) badFormat :(NSString*)text;
/* private */ + (XS_BigInteger*) DC1 :(xs_int)p1 :(xs_int)p2 :(xs_int)p3 :(xs_int)p4 :(xs_int)p5 :(xs_int)p6 :(xs_byte)p7;
@end

#define XS_BigInteger_DIGIT_SIZE 6
#define XS_BigInteger_SINGLE_ZERO 0
#define XS_BigInteger_DOUBLE_ZERO 0
#define XS_BigInteger_SINGLE_LIMIT 1000000
#define XS_BigInteger_DOUBLE_LIMIT XS_LONG(1000000000000)
#define XS_BigInteger_LOW_INDEX 1
#define XS_BigInteger_HIGH_INDEX 6
#define XS_BigInteger_MIN_SBYTE -128
#define XS_BigInteger_MAX_SBYTE 127
#define XS_BigInteger_MIN_INT16 -32768
#define XS_BigInteger_MAX_INT16 32767
#define XS_BigInteger_XS_INTEGER YES
#define XS_BigInteger_XS_DECIMAL NO

#endif
