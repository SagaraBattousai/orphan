#ifndef __ORPHAN_BIGINT_H__
#define __ORPHAN_BIGINT_H__

#include <cstdint>
#include <vector>
#include <string>

#include <orphan/_orphanconfig.h>
#include <orphan/orphan-integral.h>

namespace orphan
{
	struct ORPHAN_LOCAL_SYMBOL AdderResult
	{
		//unsigned int over uint8_t as larger, natural and faster (I hope)
		unsigned int Sum;
		unsigned int CarryOut;
	};

	ORPHAN_LOCAL_SYMBOL AdderResult 
		Byte_Adder(unsigned int a, unsigned int b, unsigned int carry_in);

	class ORPHAN_EXPORT_SYMBOL BigInt
	{
	public:
		BigInt(unsigned long long n = 0);
		BigInt(std::string hex_string = "0x00");
		BigInt(const BigInt&);
		BigInt(BigInt&&);

		BigInt& operator+=(const BigInt& rhs);
		friend BigInt operator+(BigInt lhs, const BigInt& rhs);
		
		BigInt& operator-=(const BigInt& rhs);
		friend BigInt operator-(BigInt lhs, const BigInt& rhs);

		BigInt& operator*=(const BigInt& rhs);
		friend BigInt operator*(BigInt lhs, const BigInt& rhs);

		BigInt& operator/=(const BigInt& rhs);
		friend BigInt operator/(BigInt lhs, const BigInt& rhs);

		BigInt& operator++();
		BigInt operator++(int);

		BigInt& operator--();
		BigInt operator--(int);

		BigInt& operator%=(const BigInt& rhs);
		friend BigInt operator%(BigInt lhs, const BigInt& rhs);


	private:
		//Stored as vector of bytes in little endian order
		std::vector<integral_digit> data;
	};
}


#endif