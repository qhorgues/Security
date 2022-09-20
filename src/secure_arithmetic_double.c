#include <float.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

double secure_add_d(double const a, double const b)
{
	int const positive_result = a > -b;
	double ret_value = positive_result ? DBL_MAX : -DBL_MAX;
	double a1 = a;
	double b1 = b;

	if (a1 == -b1)
		return 0;
	else if ((a1 < 0) != (b1 < 0))
	{
		/* On se ramène au cas où a <= 0 et b >= 0 */
		if (a1 <= 0)
		{
			double t = a1;
			a1 = b1;
			b1 = t;
		}
		if (-DBL_MIN - a1 < b1 && a1 < DBL_MIN - b1) 
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

		if (a1 > DBL_MAX - b1)	
			goto overflow;

		if (negative)
		{
			a1 = -a1;
			b1 = -b1;
		}
	}

	return a1 + b1;

underflow:
	ret_value = positive_result ? DBL_MIN : -DBL_MIN;		
overflow:
	errno = ERANGE;
	return ret_value;
}

double secure_sub_d(double const a, double const b)
{
    return secure_add_d(a, -b);
}


double secure_mul_d(double const a, double const b)
{
	int const different_signs = (a < 0) != (b < 0);
	double ret_value = different_signs ? -DBL_MAX : DBL_MAX;

	if (fabs(b) < 1) 
	{
		if (fabs(a) < DBL_MIN / fabs(b))
			goto underflow;
	}
	else
	{
		if (fabs(a) > DBL_MAX / fabs(b))
			goto overflow;
	}	

	return a * b;

underflow:
	ret_value = different_signs ? -DBL_MIN : DBL_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}


double secure_div_d(double const a, double const b)
{
	int const different_signs = (a < 0) != (b < 0);
	double ret_value = different_signs ? -DBL_MAX : DBL_MAX;

	if (b == 0)
	{
		errno = EDOM;
		return ret_value;	
	}
	else if (fabs(b) < 1)
	{
		if (fabs(a) > DBL_MAX * fabs(b))
			goto overflow;
	}
	else
	{
		if (fabs(a) < DBL_MIN * fabs(b))
			goto underflow;
	}

	return a / b;

underflow:
	ret_value = different_signs ? -DBL_MIN : DBL_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}