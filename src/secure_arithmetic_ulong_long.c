#include <limits.h>
#include <errno.h>


unsigned long long secure_add_ull(unsigned long long const a, unsigned long long const b)
{
	if (a > ULLONG_MAX - b)
		goto overflow;
	
	return a + b;

overflow:
	errno = ERANGE;
	return ULLONG_MAX;
}


unsigned long long secure_sub_ull(unsigned long long const a, unsigned long long const b)
{
    if (a < b)
        goto underflow;

    return a - b;
underflow:
	errno = ERANGE;
    return 0;
}

unsigned long long secure_neg_ull(unsigned long long const a)
{
	return secure_sub_ull(0, a);
}

unsigned long long secure_mul_ull(unsigned long long const a, unsigned long long const b)
{
	if (a > 0 && a > ULLONG_MAX / b)
		goto overflow;

	return a * b;

overflow:
	errno = ERANGE;
	return ULLONG_MAX;
}


unsigned long long secure_div_ull(unsigned long long const a, unsigned long long const b)
{
	return a / b;
}

unsigned long long secure_mod_ull(unsigned long long const a, unsigned long long const b)
{
	return a % b;
}