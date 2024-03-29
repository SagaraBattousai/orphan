#ifndef __ORPHAN_INTEGRAL_H__
#define __ORPHAN_INTEGRAL_H__
/**@file */

#include <orphan/_orphanconfig.h>

 /**
	* Typedefs and constant values required for core integral operations.
	* Theses are split for C and C++ (despite not being neccisary) to promote
	* good style.
	*/
#ifndef __cplusplus
#include <stdint.h>

	//Originally types were based on processor;
	//However now we will stick to the same on all processors
typedef uint32_t integral_digit;
typedef int32_t	 sintegral_digit; // Signed digit
typedef uint64_t double_digit;    // Or ddigit like dword?
typedef int64_t  sdouble_digit;   // Signed double_digit

#define BITS_IN_DIGIT          30
#define INTEGRAL_SHIFT         BITS_IN_DIGIT
#define INTEGRAL_DECIMAL_SHIFT 9 // Max(e such that 10**e fits in a digit)
#define INTEGRAL_DECIMAL_BASE  ((integral_digit) 1000000000)  // 10 ** DECIMAL_SHIFT
#define INTEGRAL_BASE          ((integral_digit) 0x40000000) // A.K.A (1 << INTEGRAL_SHIFT)
#define INTEGRAL_MASK          ((integral_digit) 0x3FFFFFFF) // A.K.A (INTEGRAL_BASE - 1)

#else

#include <cstdint>

	//Originally types were based on processor;
	//However now we will stick to the same on all processors
using integral_digit = std::uint32_t;
using sintegral_digit = std::int32_t;  // Signed digit
using double_digit = std::uint64_t; // Or ddigit like dword?
using sdouble_digit = std::int64_t;  // Signed double_digit

constexpr auto BITS_IN_DIGIT = 30;
constexpr auto INTEGRAL_SHIFT = BITS_IN_DIGIT;
constexpr auto INTEGRAL_DECIMAL_SHIFT = 9; // Max(e such that 10**e fits in a digit)
constexpr integral_digit INTEGRAL_DECIMAL_BASE = 1000000000;  // 10 ** DECIMAL_SHIFT
constexpr integral_digit INTEGRAL_BASE = 0x40000000; // A.K.A (1 << INTEGRAL_SHIFT)
constexpr integral_digit INTEGRAL_MASK = 0x3FFFFFFF; // A.K.A (INTEGRAL_BASE - 1)

#include <vector>
#include <ostream>

namespace orphan
{
	/**
	 * @brief Divides a large numbers (an array of integral digits) by a single integral digit.
	 * @param[out] div stores the result of dividing lhs by rhs.
	 * @param[in] lhs left hand side.
	 * @param lhs_size left hand side size.
	 * @param rhs right hand side single digit.
	 * @returns remainder of lhs divided by rhs.
	 */
	 //integral_digit ORPHAN_LOCAL_SYMBOL
	 //	digit_div_rem(integral_digit* div, const integral_t* lhs, int lhs_size, const integral_digit rhs);

	class ORPHAN_EXPORT_SYMBOL Integral
	{
	private:
		using integral = std::vector<integral_digit>;

	public:
		Integral(unsigned long long absolute, std::int8_t sign = 1);

		//Integral(std::string hex_string = "0x00");

		//Integral(const Integral&);

		//static constexpr
		static Integral Zero()
		{
			return Integral();
		}

		Integral& operator+=(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator+(Integral lhs, const Integral& rhs);

		Integral& operator-=(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator-(Integral lhs, const Integral& rhs);

		Integral& operator*=(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator*(Integral lhs, const Integral& rhs);

		Integral& operator/=(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator/(Integral lhs, const Integral& rhs);

		Integral& divRem(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral divRem(Integral lhs, const Integral& rhs);

		Integral& operator++();
		Integral operator++(int);

		Integral& operator--();
		Integral operator--(int);

		Integral& operator%=(const Integral& rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator%(Integral lhs, const Integral& rhs);

		Integral& operator<<=(int rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator<<(Integral lhs, int rhs);

		Integral& operator>>=(int rhs);
		friend ORPHAN_EXPORT_SYMBOL Integral operator>>(Integral lhs, int rhs);

		friend ORPHAN_EXPORT_SYMBOL std::ostream& operator<<(std::ostream& os, const Integral& obj);

	private:
		//constexpr Integral();
		//Private constructor for Zero (faster than other???)
		//constexpr
		Integral()
			: digits{ integral{0} }
			, sign{ 1 }
		{}

		Integral(int num_digits, std::int8_t sign = 1)
			: digits{ integral(num_digits) }
			, sign{ sign }
		{}


		void set_digits(integral::size_type count);

		//Stored as vector of Base 30 digits in little endian order
		integral digits;
		std::int8_t sign;
	};
}
#endif

/* For C interop */

#ifdef __cplusplus
typedef orphan::Integral integral_t;
#else
typedef struct Integral integral_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

	ORPHAN_EXPORT_SYMBOL integral_t* new_integral(unsigned long long absolute);

	ORPHAN_EXPORT_SYMBOL integral_t* new_unsigned_integral(unsigned long long absolute);

	ORPHAN_EXPORT_SYMBOL void free_integral(integral_t* number);

	ORPHAN_EXPORT_SYMBOL integral_t* add_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL integral_t* sub_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL integral_t* mult_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL integral_t* div_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL integral_t* div_rem_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL integral_t* mod_integral(const integral_t* lhs, const integral_t* rhs);

	ORPHAN_EXPORT_SYMBOL void inc_integral(integral_t* value);

	ORPHAN_EXPORT_SYMBOL void dec_integral(integral_t* value);

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
	ORPHAN_EXPORT_SYMBOL integral_digit
		lshift_integral(integral_digit* dst, const integral_digit* src, int count, int shift);

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
	ORPHAN_EXPORT_SYMBOL integral_digit
		rshift_integral(integral_digit* dst, const integral_digit* src, int count, int shift);


#ifdef __cplusplus
}
#endif

#endif
