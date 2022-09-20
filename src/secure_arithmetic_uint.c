#include <limits.h>
#include <errno.h>


unsigned int secure_add_ui(unsigned int const a, unsigned int const b)
{
	if (a > UINT_MAX - b)
		goto overflow;
	
	return a + b;

overflow:
	errno = ERANGE;
	return UINT_MAX;
}


unsigned int secure_sub_ui(unsigned int const a, unsigned int const b)
{
    if (a < b)
        goto underflow;

    return a - b;
underflow:
	errno = ERANGE;
    return 0;
}

unsigned int secure_neg_ui(unsigned int const a)
{
	return secure_sub_ui(0, a);
}

unsigned int secure_mul_ui(unsigned int const a, unsigned int const b)
{
	if (a > 0 && a > UINT_MAX / b)
		goto overflow;

	return a * b;

overflow:
	errno = ERANGE;
	return UINT_MAX;
}


unsigned int secure_div_ui(unsigned int const a, unsigned int const b)
{
	return a / b;
}

unsigned int secure_mod_ui(unsigned int const a, unsigned int const b)
{
	return a % b;
}