#include <limits.h>
#include <errno.h>


short secure_add_s(short const a, short const b)
{
	int err = 1;

	if (b >= 0 && a > SHRT_MAX - b)
		goto overflow;
	else if (b < 0 && a < SHRT_MIN - b)
		goto underflow;

	return a + b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? SHRT_MAX : SHRT_MIN;
}


short secure_sub_s(short const a, short const b)
{
    int err = 1;

    if (b >= 0 && a < SHRT_MIN + b)
        goto underflow;
    else if (b < 0 && a > SHRT_MAX + b)
        goto overflow;

    return a - b;
underflow:
    err = -1;
overflow:
    errno = ERANGE;
    return err > 0 ? SHRT_MAX : SHRT_MIN;
}

short secure_neg_s(short const a)
{
	return secure_sub_s(0, a);
}

short secure_mul_s(short const a, short const b)
{
	int err = 1;

	if (b > 0)
	{
		if (a > 0 && a > SHRT_MAX / b)
			goto overflow;
		else if (a < 0 && a < SHRT_MIN / b)
			goto underflow;
	}
	else if (b < 0)
	{
		if (a < 0 && a < SHRT_MAX / b)
			goto overflow;
		else if ((-SHRT_MAX > SHRT_MIN && b < -1) && a > SHRT_MIN / b)
			goto underflow;
	}

	return a * b;
underflow:
	err = -1;
overflow:
	errno = ERANGE;
	return err > 0 ? SHRT_MAX : SHRT_MIN;
}


short secure_div_s(short const a, short const b)
{
	if (-SHRT_MAX > SHRT_MIN && b == -1 && a == SHRT_MIN)
	{
		errno = ERANGE;
		return SHRT_MIN;
	}

	return a / b;
}

short secure_mod_s(short const a, short const b)
{
	if (-SHRT_MAX > SHRT_MIN && b == -1 && a == SHRT_MIN)
	{
		errno = ERANGE;
		return SHRT_MIN;
	}

	return a % b;
}