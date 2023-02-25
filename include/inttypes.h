#ifndef _INTTYPES_H
#define _INTTYPES_H

#define NULL ((void*)0)
#define sti (asm volatile("sti");) // set interrupt flag

// Limits
#define INT8_MIN		(-128)
#define INT16_MIN 		(-32768)
#define INT32_MIN		(-2147483647 - 1)
#define INT64_MIN		(-9223372036854775807LL - 1)

#define INT8_MAX 		127
#define INT16_MAX		32767
#define INT32_MAX 		2147483647
#define INT64_MAX 		9223372036854775807LL

#define UINT8_MAX 		0xFF
#define UINT16_MAX		0xFFFF
#define UINT32_MAX		0xFFFFFFFF
#define UINT64_MAX		0xFFFFFFFFFFFFFFFFULL

// Data Types
#define low_16(address) 	(uint16_t)((address) & 0xFFFF)
#define high_16(address) 	(uint16_t)(((address) >> 16) & 0xFFFF)

typedef unsigned int size_t;

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#endif // _INTTYPES_H
