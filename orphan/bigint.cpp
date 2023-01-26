
#include <orphan/orphan-bigint.h>

namespace orphan
{
	namespace {
		constexpr int BITS_IN_A_BYTE = 8;
		constexpr int BITS_IN_UNSIGNED_INT = sizeof(unsigned int) * BITS_IN_A_BYTE;
		constexpr int BITS_BEFORE_CARRY = BITS_IN_UNSIGNED_INT - 1;

	}

	//should I use carry out as scratch as well as return or is stack faster?
	AdderResult Byte_Adder(unsigned int a, unsigned int b, unsigned int carry_in)
	{
		const unsigned int P = a ^ b;
		const unsigned int G = a & b;

		unsigned int carry = carry_in;

		unsigned int g_i;
		unsigned int p_i;
		unsigned int c_i = carry_in;

		//TODO: Should I split out carry code to try and help with threading? 
		//C_i+1 = G_i + (P_i * C_i)
		for (int i = 0; i < BITS_IN_UNSIGNED_INT; i++)
		{
			g_i = (G >> i) & 0x01;
			p_i = (P >> i) & 0x01;
			c_i = (g_i | (p_i & c_i)) & 0x01;

			if (i < BITS_BEFORE_CARRY)
			{
				carry |= (c_i << (i + 1));
			}
		}

		return AdderResult{ .Sum = P ^ carry, .CarryOut = c_i };
	}

	BigInt::BigInt(unsigned long long n)
	{

	}
	BigInt::BigInt(std::string hex_string)
	{

	}
	BigInt::BigInt(const BigInt&)
	{

	}
	BigInt::BigInt(BigInt&& other) :data{ std::move(other.data) } {} //???

	BigInt& BigInt::operator+=(const BigInt& rhs)
	{

	}

	BigInt operator+(BigInt lhs, const BigInt& rhs)
	{

	}

	BigInt& BigInt::operator-=(const BigInt& rhs)
	{

	}

	BigInt operator-(BigInt lhs, const BigInt& rhs)
	{

	}

	BigInt& BigInt::operator*=(const BigInt& rhs) 
	{

	}

	BigInt operator*(BigInt lhs, const BigInt& rhs)
	{

	}

	BigInt& BigInt::operator/=(const BigInt& rhs)
	{

	}

	BigInt operator/(BigInt lhs, const BigInt& rhs)
	{

	}

	BigInt& BigInt::operator++()
	{

	}

	BigInt BigInt::operator++(int)
	{

	}

	BigInt& BigInt::operator--()
	{

	}

	BigInt BigInt::operator--(int)
	{

	}

	BigInt& BigInt::operator%=(const BigInt& rhs)
	{

	}

	BigInt operator%(BigInt lhs, const BigInt& rhs)
	{

	}

}