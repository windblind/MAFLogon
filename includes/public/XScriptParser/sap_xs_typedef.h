#ifndef SAP_XS_TYPEDEF_H
#define SAP_XS_TYPEDEF_H

#import <stdint.h>

// Use #defines, not typedefs, to avoid XCode debugging issues!

#define xs_boolean BOOL
#define xs_char unichar
#define xs_byte signed char
#define xs_short int16_t
#define xs_int int32_t
#define xs_long int64_t
#define xs_float float
#define xs_double double

#define XS_LONG(value) value##LL

// #define xs_integer NSDecimal
// #define xs_decimal NSDecimal

#define xs_integer XS_BigInteger*
#define xs_decimal XS_BigDecimal*

#define xs_ubyte unsigned char
#define xs_ushort uint16_t
#define xs_uint uint32_t
#define xs_ulong uint64_t

#define XS_NULLABLE_TYPE(NullableStruct, NullableType, ValueType) \
    struct NullableStruct \
    { \
        xs_boolean isNull; \
        ValueType value; \
    }; \
    typedef struct NullableStruct NullableType

XS_NULLABLE_TYPE(XS_NULLABLE_BOOLEAN, xs_nullable_boolean, xs_boolean);
XS_NULLABLE_TYPE(XS_NULLABLE_CHAR, xs_nullable_char, xs_char);
XS_NULLABLE_TYPE(XS_NULLABLE_BYTE, xs_nullable_byte, xs_byte);
XS_NULLABLE_TYPE(XS_NULLABLE_SHORT, xs_nullable_short, xs_short);
XS_NULLABLE_TYPE(XS_NULLABLE_INT, xs_nullable_int, xs_int);
XS_NULLABLE_TYPE(XS_NULLABLE_LONG, xs_nullable_long, xs_long);
XS_NULLABLE_TYPE(XS_NULLABLE_FLOAT, xs_nullable_float, xs_float);
XS_NULLABLE_TYPE(XS_NULLABLE_DOUBLE, xs_nullable_double, xs_double);

#define XS_NULL_BOOLEAN ((xs_nullable_boolean){YES,(xs_boolean)0})
#define XS_NULL_CHAR ((xs_nullable_char){YES,(xs_char)0})
#define XS_NULL_BYTE ((xs_nullable_byte){YES,(xs_byte)0})
#define XS_NULL_SHORT ((xs_nullable_short){YES,(xs_short)0})
#define XS_NULL_INT ((xs_nullable_int){YES,(xs_int)0})
#define XS_NULL_LONG ((xs_nullable_long){YES,(xs_long)0})
#define XS_NULL_FLOAT ((xs_nullable_float){YES,(xs_float)0})
#define XS_NULL_DOUBLE ((xs_nullable_double){YES,(xs_double)0})

// #define xs_nullable_integer NSNumber*
// #define xs_nullable_decimal NSNumber*

#define xs_nullable_integer XS_BigInteger*
#define xs_nullable_decimal XS_BigDecimal*

#include "sap_xs_integer.h"
#include "sap_xs_decimal.h"

#endif
