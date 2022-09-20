#include <limits.h>
#include <errno.h>


int secure_add_i(int const a, int const b)
{
	int err = 1;

	if (b >= 0 && a > INT_MAX - b)
		goto overflow;
	else if (b < 0 && a < INT_MIN - b)
		goto underflow;

	return a + b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? INT_MAX : INT_MIN;
}


int secure_sub_i(int const a, int const b)
{
    int err = 1;

    if (b >= 0 && a < INT_MIN + b)
        goto underflow;
    else if (b < 0 && a > INT_MAX + b)
        goto overflow;

    return a - b;
underflow:
    err = -1;
overflow:
    errno = ERANGE;
    return err > 0 ? INT_MAX : INT_MIN;
}

int secure_neg_i(int const a)
{
	return secure_sub_i(0, a);
}

int secure_mul_i(int const a, int const b)
{
	int err = 1;

	if (b > 0)
	{
		if (a > 0 && a > INT_MAX / b)
			goto overflow;
		else if (a < 0 && a < INT_MIN / b)
			goto underflow;
	}
	else if (b < 0)
	{
		if (a < 0 && a < INT_MAX / b)
			goto overflow;
		else if ((-INT_MAX > INT_MIN && b < -1) && a > INT_MIN / b)
			goto underflow;
	}

	return a * b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? INT_MAX : INT_MIN;
}


int secure_div_i(int const a, int const b)
{
	if (-INT_MAX > INT_MIN && b == -1 && a == INT_MIN)
	{
		errno = ERANGE;
		return INT_MIN;
	}

	return a / b;
}

int secure_mod_i(int const a, int const b)
{
	if (-INT_MAX > INT_MIN && b == -1 && a == INT_MIN)
	{
		errno = ERANGE;
		return INT_MIN;
	}

	return a % b;
}