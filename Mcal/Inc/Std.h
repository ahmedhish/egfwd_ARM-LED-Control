#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Useful abbreviations to use:
#define INPUT  (0U)
#define OUTPUT (1U)

#define STD_LOW   0x00U
#define STD_HIGH  0x01U


// A file to count ALL Data-Types with the formation of specific shortcuts for them:

//       *Data Type*           *Symbol*        *Format Specifier*
typedef unsigned char           uint8;          //      %c
typedef   signed char            int8;          //      %c
typedef unsigned short int      uint16;         //      %hu
typedef   signed short int       int16;         //      %hd
typedef unsigned long  int      uint32;         //      %lu
typedef   signed long  int       int32;         //      %ld
/* For [int]:
 * at least(2-bytes), usually (4-bytes):
 *    typedef unsigned int      uint16; [Repeated]      %u
 *                         -or- uint32; [Repeated]                
 *    typedef   signed int       int16; [Repeated]      %d
 *                         -or-  int32  [Repeated]
 */
typedef unsigned long long int  uint64;         //      %lld
typedef   signed long long int   int64;         //      %llu
typedef float                   float32;        //      %f
typedef double                  float64;        //      %lf
typedef long double             float128;       //      %llf
typedef enum {false,true}       boolean;

// same Data Types but in Pointer State:
typedef unsigned char*           uint8_ptr;
typedef   signed char*            int8_ptr;
typedef unsigned short int*      uint16_ptr;
typedef   signed short int*       int16_ptr;
typedef unsigned long  int*      uint32_ptr;
typedef   signed long  int*       int32_ptr;
typedef unsigned long long int*  uint64_ptr;
typedef   signed long long int*   int64_ptr;
typedef float*                   float32_ptr;
typedef double*                  float64_ptr;
typedef long double*             float128_ptr;

#define NULL_PTR                 ((void*)0)

#endif /* STD_TYPES_H_ */