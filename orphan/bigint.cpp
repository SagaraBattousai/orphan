
#include <orphan/orphan-bigint.h>
#include <orphan/orphan-integral.h>


namespace orphan
{

	BigInt::BigInt(unsigned long long n, std::int8_t sign)
		: sign{ sign }
	{
		if (n == 0)
		{
			//Should just use Zero but allows for "negative" zero
			this->digits = integral{ 0 };
		}
		else
		{
			this->digits = integral();
			while (n != 0)
			{
				this->digits.push_back(n % INTEGRAL_BASE);
				n /= INTEGRAL_BASE; //Integer division expected
			}
		}
	}
/*
	BigInt::BigInt(std::string hex_string)
	{

	}

	BigInt::BigInt(const BigInt&)
	{

	}
	*/

	BigInt& BigInt::operator+=(const BigInt& rhs)
	{
		//ordinarily we would want to use the larger of the two as the
		//source but hopefully with vector this optimisation will be unnecisary
		const integral *a = &this->digits; //must be const ??
		const integral *b = &(rhs.digits); //must be const !!

		integral::size_type size_a = this->digits.size();
		integral::size_type size_b = rhs.digits.size();
		
		//Note adding two max 30 bit numbers = max 31 bit number - 1 (since even)
		integral_digit carry = 0;

		if (size_a < size_b)
		{
			integral::size_type temp = size_a;
			size_a = size_b;
			size_b = temp;

			const integral *tmp = a;
			a = b;
			b = tmp;
		}

		this->set_digits(size_a + 1);

		integral::size_type iter;

		for (iter = 0; iter < size_b; ++iter)
		{
			carry += (*a)[iter] + (*b)[iter];
			this->digits[iter] = carry & INTEGRAL_MASK;
			carry >>= INTEGRAL_SHIFT;
		}
		//TODO: skip when carry is 0

		for (; iter < size_a; ++iter)
		{
			carry += (*a)[iter];
			this->digits[iter] = carry & INTEGRAL_MASK;
			carry >>= INTEGRAL_SHIFT;
		}
		this->digits[iter] = carry;

		return *this;
	}
	
	BigInt operator+(BigInt lhs, const BigInt& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	BigInt& BigInt::operator-=(const BigInt& rhs)
	{
		return *this;
	}

	BigInt operator-(BigInt lhs, const BigInt& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	BigInt& BigInt::operator*=(const BigInt& rhs)
	{
		return *this;
	}

	BigInt operator*(BigInt lhs, const BigInt& rhs)
	{
		return lhs;
	}

	BigInt& BigInt::operator/=(const BigInt& rhs)
	{
		return *this;
	}

	BigInt operator/(BigInt lhs, const BigInt& rhs)
	{
		return lhs;
	}

	BigInt& BigInt::operator++()
	{
		return *this;
	}

	BigInt BigInt::operator++(int)
	{
		return BigInt::Zero();
	}

	BigInt& BigInt::operator--()
	{
		return *this;
	}

	BigInt BigInt::operator--(int)
	{
		return BigInt::Zero();
	}

	BigInt& BigInt::operator%=(const BigInt& rhs)
	{
		return *this;
	}

	BigInt operator%(BigInt lhs, const BigInt& rhs)
	{
		return lhs;
	}

	BigInt& BigInt::operator<<=(int rhs)
	{
		return *this;
	}

	BigInt operator<<(BigInt lhs, int rhs)
	{
		return BigInt::Zero();
	}

	BigInt& BigInt::operator>>=(int rhs)
	{
		return *this;
	}

	BigInt operator>>(BigInt lhs, int rhs)
	{
		return BigInt::Zero();
	}

	
	std::ostream& operator<<(std::ostream& os, const BigInt& obj)
	{
		//TODO: Just for now, do not leave, do not commit!
		os << (int)obj.digits[0];
		return os;
	}
	

	void BigInt::set_digits(integral::size_type count)
	{
		integral::size_type size_diff = this->digits.size();

		if (size_diff >= count)
			return;

		size_diff = count - size_diff;

		while (size_diff > 0)
		{
			this->digits.emplace_back();
			--size_diff;
		}

	}





}
