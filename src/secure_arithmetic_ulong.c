#include <limits.h>
#include <errno.h>


unsigned long secure_add_ul(unsigned long const a, unsigned long const b)
{
	if (a > ULONG_MAX - b)
		goto overflow;
	
	return a + b;

overflow:
	errno = ERANGE;
	return ULONG_MAX;
}


unsigned long secure_sub_ul(unsigned long const a, unsigned long const b)
{
    if (a < b)
        goto underflow;

    return a - b;
underflow:
	errno = ERANGE;
    return 0;
}

unsigned long secure_neg_ul(unsigned long const a)
{
	return secure_sub_ul(0, a);
}

unsigned long secure_mul_ul(unsigned long const a, unsigned long const b)
{
	if (a > 0 && a > ULONG_MAX / b)
		goto overflow;

	return a * b;

overflow:
	errno = ERANGE;
	return ULONG_MAX;
}


unsigned long secure_div_ul(unsigned long const a, unsigned long const b)
{
	return a / b;
}

unsigned long secure_mod_ul(unsigned long const a, unsigned long const b)
{
	return a % b;
}