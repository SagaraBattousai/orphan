
#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdint>

#include <orphan/orphan-integral.h>
#include <orphan/orphan-integral.h>


int main()
{
	orphan::Integral x{ (unsigned long long) 32 };
	orphan::Integral y{ (unsigned long long) 154 };

	char z = 4 << (unsigned)3;

	std::cout << (x+y) << " = " << 32 + 154 << std::endl;

	return 0;
}