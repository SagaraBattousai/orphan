#ifndef __ORPHAN_INTEGRAL_H__
#define __ORPHAN_INTEGRAL_H__

/**@file */

//Use C headers over C++ ones in order to remove requirement
//for std::
#include <stdint.h>
#include <stddef.h>
#include <orphan/_orphanconfig.h>

#ifdef __cplusplus
extern "C" {
#endif

//Originally types were based on processor;
//However now we will stick to the same on all processors

typedef uint32_t integral_digit;
typedef int32_t	 sintegral_digit; // Signed digit
typedef uint64_t double_digit;    // Or ddigit like dword?
typedef int64_t  sdouble_digit;   // Signed double_digit

#define BITS_IN_DIGIT          30
#define INTEGRAL_SHIFT         30
#define INTEGRAL_DECIMAL_SHIFT 9 // Max(e such that 10**e fits in a digit)
#define INTEGRAL_DECIMAL_BASE  ((integral_digit) 1000000000)  // 10 ** DECIMAL_SHIFT
#define INTEGRAL_BASE          ((integral_digit) 0x40000000) // A.K.A (1 << INTEGRAL_SHIFT)
#define INTEGRAL_MASK          ((integral_digit) 0x3FFFFFFF) // A.K.A (INTEGRAL_BASE - 1)


/**
 * @brief Computes the left shift of an integral
 * @pre dst is an array with size >= count.
 * @pre 0 <= shift < INTEGRAL_SHIFT (otherwise the result is undefined).
 * @pre 0 <= count <= size of src
 * @param[out] dst stores the rsult of shifting src shift bits to the left.
 * @param[in] src contains the data to be shifted.
 * @param count the size of src array to shift.
 * @param shift the amount to shift src by.
 * @return The "shift" bits that were shifted out of the top
 */
integral_digit ORPHAN_EXPORT_SYMBOL 
lshift(integral_digit *dst, const integral_digit *src, int count, int shift);

/**
 * @brief Computes the right shift of an integral
 * @pre dst is an array with size >= count.
 * @pre 0 <= shift < INTEGRAL_SHIFT (otherwise the result is undefined).
 * @pre 0 <= count <= size of src
 * @param[out] dst stores the rsult of shifting src shift bits to the right.
 * @param[in] src contains the data to be shifted.
 * @param count the size of src array to shift.
 * @param shift the amount to shift src by.
 * @return The "shift" bits that were shifted out of the bottom
 */
integral_digit ORPHAN_EXPORT_SYMBOL
rshift(integral_digit *dst, const integral_digit *src, int count, int shift);


#ifdef __cplusplus
}
#endif

#endif