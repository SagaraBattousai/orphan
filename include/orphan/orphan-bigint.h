#ifndef __ORPHAN_BIGINT_H__
#define __ORPHAN_BIGINT_H__

#include <cstdint>
#include <vector>
#include <ostream>

#include <orphan/_orphanconfig.h>
#include <orphan/orphan-integral.h>

namespace orphan
{

	class ORPHAN_EXPORT_SYMBOL BigInt
	{
	private:
		using integral = std::vector<integral_digit>;

	public:
		BigInt(unsigned long long absolute, std::int8_t sign = 1);

		//BigInt(std::string hex_string = "0x00");

		//BigInt(const BigInt&);

		static constexpr BigInt Zero()
		{
			return BigInt();
		}

		BigInt& operator+=(const BigInt& rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator+(BigInt lhs, const BigInt& rhs);
		
		BigInt& operator-=(const BigInt& rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator-(BigInt lhs, const BigInt& rhs);

		BigInt& operator*=(const BigInt& rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator*(BigInt lhs, const BigInt& rhs);

		BigInt& operator/=(const BigInt& rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator/(BigInt lhs, const BigInt& rhs);

		BigInt& operator++();
		BigInt operator++(int);

		BigInt& operator--();
		BigInt operator--(int);

		BigInt& operator%=(const BigInt& rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator%(BigInt lhs, const BigInt& rhs);

		BigInt& operator<<=(int rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator<<(BigInt lhs, int rhs);

		BigInt& operator>>=(int rhs);
		friend ORPHAN_EXPORT_SYMBOL BigInt operator>>(BigInt lhs, int rhs);

		friend ORPHAN_EXPORT_SYMBOL std::ostream& operator<<(std::ostream& os, const BigInt& obj);

	private:
		//constexpr BigInt();
		//Private constructor for Zero (faster than other???)
		constexpr BigInt()
			: digits{ integral{0} }
			, sign{ 1 }
		{}
		
		
		void set_digits(integral::size_type count);

		//Stored as vector of Base 30 digits in little endian order
		integral digits;
		std::int8_t sign;
	};
}


#endif