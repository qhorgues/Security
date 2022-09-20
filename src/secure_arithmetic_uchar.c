#include <limits.h>
#include <errno.h>


unsigned char secure_add_uc(unsigned char const a, unsigned char const b)
{
	if (a > UCHAR_MAX - b)
		goto overflow;
	
	return a + b;

overflow:
	errno = ERANGE;
	return UCHAR_MAX;
}


unsigned char secure_sub_uc(unsigned char const a, unsigned char const b)
{
    if (a < b)
        goto underflow;

    return a - b;
underflow:
	errno = ERANGE;
    return 0;
}

unsigned char secure_neg_uc(unsigned char const a)
{
	return secure_sub_uc(0, a);
}

unsigned char secure_mul_uc(unsigned char const a, unsigned char const b)
{
	if (a > 0 && a > UCHAR_MAX / b)
		goto overflow;

	return a * b;

overflow:
	errno = ERANGE;
	return UCHAR_MAX;
}


unsigned char secure_div_uc(unsigned char const a, unsigned char const b)
{
	return a / b;
}

unsigned char secure_mod_uc(unsigned char const a, unsigned char const b)
{
	return a % b;
}