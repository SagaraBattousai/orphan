#include <orphan/orphan-integral.h>

#include <cstring>


integral_digit 
lshift(integral_digit *dst, const integral_digit *src, int count, int shift)
{
	integral_digit carry = 0;
	double_digit acc;

	for (int i = 0; i < count; ++i)
	{
		acc = ((double_digit)src[i] << shift) | carry;
		dst[i] = (integral_digit)acc & INTEGRAL_MASK;
		carry = (integral_digit)(acc >> INTEGRAL_SHIFT);
	}
	return carry;
}

integral_digit
rshift(integral_digit *dst, const integral_digit *src, int count, int shift)
{
	integral_digit carry = 0;
	integral_digit shift_mask = ((integral_digit)1 << shift) - 1;
	double_digit acc;

	for (int i = count; i >= 0; --i)
	{
		acc = ((double_digit)carry << INTEGRAL_SHIFT) | src[i];
		carry = (integral_digit)acc & shift_mask;
		dst[i] = (integral_digit)(acc >> shift);
	}

	return carry;
}