
#include <iostream>
#include <cmath>
#include <cstdint>
#include <cactuar/cactuar-sha.h>


int main()
{
	//std::uint64_t mult = (std::uint64_t)1 << 32;
	//double x;
	//double msr = modf(sqrt(2), &x);

	//double mmsr = sqrt(2) - ((int)(sqrt(2)));

  double sr = cactuar::placeholder();

	std::cout << std::sqrt(2) << " - " << sr << " = " << (std::sqrt(2) - sr) << std::endl;



	return 0;
}