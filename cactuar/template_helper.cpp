
//#include <cmath>
#include <iostream>

#include <cactuar/cactuar-sha.h>

namespace cactuar
{
	template<std::integral T>
	constexpr bool IsPrime(T value)
	{
		if (value < 2) return false;

		switch (value)
		{
			case 2:
			case 3:
				return true;
			default:
			{
				for (T k = 4; k * k <= value; k++)
				{
					if (value % k == 0)
					{
						return false;
					}
				}
				return true;
			}
		}
	}

	template<int COUNT, typename VALUETYPE = std::uint32_t>
	constexpr std::array<VALUETYPE, COUNT> primes = [] {
		std::array<VALUETYPE, COUNT> arr = {};
		int i = 0;
		for (std::uint32_t c = 2; i < COUNT; c++)
		{
			if (IsPrime(c))
			{
				arr[i] = c;
				i++;
			}
		}

		return arr;

	}();

	template<double value>
	constexpr double sqrt_approx()
	{
		//can do it cleaverer but simplicity is king
		if constexpr (value < 8)
		{
			return (1.0 / 4) * value + 1;
		}
		else if constexpr (value < 32)
		{
			return (1.0 / 8) * value + 2;
		}
		else if constexpr (value < 128)
		{
			return (1.0 / 16) * value + 4;
		}
		else if constexpr (value < 512)
		{
			return (1.0 / 32) * value + 8;
		}
		else if constexpr (value < 2048)
		{
			return (1.0 / 64) * value + 16;
		}
		else if constexpr (value < 8192)
		{
			return (1.0 / 128) * value + 32;
		}
		else // value < 32,768
		{
			return (1.0 / 256) * value + 64;
		}
	}

	template<double value>
	constexpr double sqrt()
	{
		double guess = sqrt_approx<value>();
		double a;
		double b;
		int i = 0;
		while (i < 10)
		{
			a = (value - (guess * guess)) / (2 * guess);
			b = guess + a;
			guess = b - ((a * a) / (2 * b));
			i++;
		}
		return guess;
	}

	/*
	constexpr std::uint32_t con()
	{
		std::array<std::uint32_t, 1> pri = primes<1>;
		std::uint64_t mult = (std::uint64_t)1 << 32;
		double x;
		double msr = modf(sqrt(2), &x);

		return (std::uint32_t) (msr * mult);
	}
	*/

	constexpr int f() { return 0; }

	double placeholder()
	{
		return sqrt<2.0>();
	}


	//constexpr std::array<std::uint32_t, 8> test = [] {
	//	std::array<std::uint32_t, 8> test = {};
	//	for(std::uint32_t i = 2; )
	//
	//}();
}