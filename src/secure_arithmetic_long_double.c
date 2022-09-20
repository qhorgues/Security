#include <float.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

long double secure_add_ld(long double const a, long double const b)
{
	int const positive_result = a > -b;
	long double ret_value = positive_result ? LDBL_MAX : -LDBL_MAX;
	long double a1 = a;
	long double b1 = b;

	if (a1 == -b1)
		return 0;
	else if ((a1 < 0) != (b1 < 0))
	{
		/* On se ramène au cas où a <= 0 et b >= 0 */
		if (a1 <= 0)
		{
			long double t = a1;
			a1 = b1;
			b1 = t;
		}
		if (-LDBL_MIN - a1 < b1 && a1 < LDBL_MIN - b1) 
			goto underflow;
	}
	else 
	{
		bool negative = false;
		
		/* On se ramène au cas où a et b sont positifs */	
		if (a1 < 0)
		{
			a1 = -a1;
			b1 = -b1;
			negative = true;
		}

		if (a1 > LDBL_MAX - b1)	
			goto overflow;

		if (negative)
		{
			a1 = -a1;
			b1 = -b1;
		}
	}

	return a1 + b1;

underflow:
	ret_value = positive_result ? LDBL_MIN : -LDBL_MIN;		
overflow:
	errno = ERANGE;
	return ret_value;
}

long double secure_sub_ld(long double const a, long double const b)
{
    return secure_add_ld(a, -b);
}


long double secure_mul_ld(long double const a, long double const b)
{
	int const different_signs = (a < 0) != (b < 0);
	long double ret_value = different_signs ? -LDBL_MAX : LDBL_MAX;

	if (fabsl(b) < 1) 
	{
		if (fabsl(a) < LDBL_MIN / fabsl(b))
			goto underflow;
	}
	else
	{
		if (fabsl(a) > LDBL_MAX / fabsl(b))
			goto overflow;
	}	

	return a * b;

underflow:
	ret_value = different_signs ? -LDBL_MIN : LDBL_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}


long double secure_div_ld(long double const a, long double const b)
{
	int const different_signs = (a < 0) != (b < 0);
	long double ret_value = different_signs ? -LDBL_MAX : LDBL_MAX;

	if (b == 0)
	{
		errno = EDOM;
		return ret_value;	
	}
	else if (fabsl(b) < 1)
	{
		if (fabsl(a) > LDBL_MAX * fabsl(b))
			goto overflow;
	}
	else
	{
		if (fabsl(a) < LDBL_MIN * fabsl(b))
			goto underflow;
	}

	return a / b;

underflow:
	ret_value = different_signs ? -LDBL_MIN : LDBL_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}