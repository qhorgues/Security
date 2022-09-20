#include <limits.h>
#include <errno.h>


long secure_add_l(long const a, long const b)
{
	int err = 1;

	if (b >= 0 && a > LONG_MAX - b)
		goto overflow;
	else if (b < 0 && a < LONG_MIN - b)
		goto underflow;

	return a + b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? LONG_MAX : LONG_MIN;
}


long secure_sub_l(long const a, long const b)
{
    int err = 1;

    if (b >= 0 && a < LONG_MIN + b)
        goto underflow;
    else if (b < 0 && a > LONG_MAX + b)
        goto overflow;

    return a - b;
underflow:
    err = -1;
overflow:
    errno = ERANGE;
    return err > 0 ? LONG_MAX : LONG_MIN;
}

long secure_neg_l(long const a)
{
	return secure_sub_l(0, a);
}

long secure_mul_l(long const a, long const b)
{
	int err = 1;

	if (b > 0)
	{
		if (a > 0 && a > LONG_MAX / b)
			goto overflow;
		else if (a < 0 && a < LONG_MIN / b)
			goto underflow;
	}
	else if (b < 0)
	{
		if (a < 0 && a < LONG_MAX / b)
			goto overflow;
		else if ((-LONG_MAX > LONG_MIN && b < -1) && a > LONG_MIN / b)
			goto underflow;
	}

	return a * b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? LONG_MAX : LONG_MIN;
}


long secure_div_l(long const a, long const b)
{
	if (-LONG_MAX > LONG_MIN && b == -1 && a == LONG_MIN)
	{
		errno = ERANGE;
		return LONG_MIN;
	}

	return a / b;
}

long secure_mod_l(long const a, long const b)
{
	if (-LONG_MAX > LONG_MIN && b == -1 && a == LONG_MIN)
	{
		errno = ERANGE;
		return LONG_MIN;
	}

	return a % b;
}