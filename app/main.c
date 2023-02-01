
#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdint>

#include <orphan/orphan-bigint.h>
#include <orphan/orphan-integral.h>


int main()
{
	orphan::BigInt x{ (unsigned long long) 32 };
	orphan::BigInt y{ (unsigned long long) 154 };

	char z = 4 << (unsigned)3;

	std::cout << (x+y) << " = " << 32 + 154 << std::endl;

	return 0;
}