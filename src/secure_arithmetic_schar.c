#include <limits.h>
#include <errno.h>


signed char secure_add_c(signed char const a, signed char const b)
{
	int err = 1;

	if (b >= 0 && a > SCHAR_MAX - b)
		goto overflow;
	else if (b < 0 && a < SCHAR_MIN - b)
		goto underflow;

	return a + b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? SCHAR_MAX : SCHAR_MIN;
}


signed char secure_sub_c(signed char const a, signed char const b)
{
    int err = 1;

    if (b >= 0 && a < SCHAR_MIN + b)
        goto underflow;
    else if (b < 0 && a > SCHAR_MAX + b)
        goto overflow;

    return a - b;
underflow:
    err = -1;
overflow:
    errno = ERANGE;
    return err > 0 ? SCHAR_MAX : SCHAR_MIN;
}

signed char secure_neg_c(signed char const a)
{
	return secure_sub_c(0, a);
}

signed char secure_mul_c(signed char const a, signed char const b)
{
	int err = 1;

	if (b > 0)
	{
		if (a > 0 && a > SCHAR_MAX / b)
			goto overflow;
		else if (a < 0 && a < SCHAR_MIN / b)
			goto underflow;
	}
	else if (b < 0)
	{
		if (a < 0 && a < SCHAR_MAX / b)
			goto overflow;
		else if ((-SCHAR_MAX > SCHAR_MIN && b < -1) && a > SCHAR_MIN / b)
			goto underflow;
	}

	return a * b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? SCHAR_MAX : SCHAR_MIN;
}


signed char secure_div_c(signed char const a, signed char const b)
{
	if (-SCHAR_MAX > SCHAR_MIN && b == -1 && a == SCHAR_MIN)
	{
		errno = ERANGE;
		return SCHAR_MIN;
	}

	return a / b;
}

signed char secure_mod_c(signed char const a, signed char const b)
{
	if (-SCHAR_MAX > SCHAR_MIN && b == -1 && a == SCHAR_MIN)
	{
		errno = ERANGE;
		return SCHAR_MIN;
	}

	return a % b;
}