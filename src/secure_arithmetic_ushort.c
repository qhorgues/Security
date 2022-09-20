#include <limits.h>
#include <errno.h>


unsigned short secure_add_us(unsigned short const a, unsigned short const b)
{
	if (a > USHRT_MAX - b)
		goto overflow;
	
	return a + b;

overflow:
	errno = ERANGE;
	return USHRT_MAX;
}


unsigned short secure_sub_us(unsigned short const a, unsigned short const b)
{
    if (a < b)
        goto underflow;

    return a - b;
underflow:
	errno = ERANGE;
    return 0;
}

unsigned short secure_neg_us(unsigned short const a)
{
	return secure_sub_us(0, a);
}

unsigned short secure_mul_us(unsigned short const a, unsigned short const b)
{
	if (a > 0 && a > USHRT_MAX / b)
		goto overflow;

	return a * b;

overflow:
	errno = ERANGE;
	return USHRT_MAX;
}


unsigned short secure_div_us(unsigned short const a, unsigned short const b)
{
	return a / b;
}

unsigned short secure_mod_us(unsigned short const a, unsigned short const b)
{
	return a % b;
}