#include <limits.h>
#include <errno.h>


long long secure_add_ll(long long const a, long long const b)
{
	int err = 1;

	if (b >= 0 && a > LLONG_MAX - b)
		goto overflow;
	else if (b < 0 && a < LLONG_MIN - b)
		goto underflow;

	return a + b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? LLONG_MAX : LLONG_MIN;
}


long long secure_sub_ll(long long const a, long long const b)
{
    int err = 1;

    if (b >= 0 && a < LLONG_MIN + b)
        goto underflow;
    else if (b < 0 && a > LLONG_MAX + b)
        goto overflow;

    return a - b;
underflow:
    err = -1;
overflow:
    errno = ERANGE;
    return err > 0 ? LLONG_MAX : LLONG_MIN;
}

long long secure_neg_ll(long long const a)
{
	return secure_sub_ll(0, a);
}

long long secure_mul_ll(long long const a, long long const b)
{
	int err = 1;

	if (b > 0)
	{
		if (a > 0 && a > LLONG_MAX / b)
			goto overflow;
		else if (a < 0 && a < LLONG_MIN / b)
			goto underflow;
	}
	else if (b < 0)
	{
		if (a < 0 && a < LLONG_MAX / b)
			goto overflow;
		else if ((-LLONG_MAX > LLONG_MIN && b < -1) && a > LLONG_MIN / b)
			goto underflow;
	}

	return a * b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? LLONG_MAX : LLONG_MIN;
}


long long secure_div_ll(long long const a, long long const b)
{
	if (-LLONG_MAX > LLONG_MIN && b == -1 && a == LLONG_MIN)
	{
		errno = ERANGE;
		return LLONG_MIN;
	}

	return a / b;
}

long long secure_mod_ll(long long const a, long long const b)
{
	if (-LLONG_MAX > LLONG_MIN && b == -1 && a == LLONG_MIN)
	{
		errno = ERANGE;
		return LLONG_MIN;
	}

	return a % b;
}