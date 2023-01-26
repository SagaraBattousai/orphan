#ifndef __ORPHAN_INTEGRAL_H__
#define __ORPHAN_INTEGRAL_H__

#ifndef __cplusplus
#include <stdint.h>
#else
#include <cstdint>
extern "C" {
#endif

//Originally types were based on processor;
//However now we will stick to the same on all processors

typedef uint32_t integral_digit;
typedef int32_t	 sintegral_digit; // Signed digit
typedef uint64_t dual_digit;
typedef int64_t  sdual_digit;     // Signed dual_digit
#define BITS_IN_DIGIT          30
#define INTEGRAL_SHIFT         30
#define INTEGRAL_DECIMAL_SHIFT 9 // Max(e such that 10**e fits in a digit)
#define INTEGRAL_DECIMAL_BASE  ((integral_digit) 1000000000)  // 10 ** DECIMAL_SHIFT
#define INTEGRAL_BASE          ((integral_digit) 0x400000000) // A.K.A (1 << INTEGRAL_SHIFT)
#define INTEGRAL_MASK          ((integral_digit) 0x03FFFFFFF) // A.K.A (INTEGRAL_BASE - 1)


#ifdef __cplusplus
}
#endif

#endif