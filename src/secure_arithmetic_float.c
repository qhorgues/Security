#include <float.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

float secure_add_f(float const a, float const b)
{
	int const positive_result = a > -b;
	float ret_value = positive_result ? FLT_MAX : -FLT_MAX;
	float a1 = a;
	float b1 = b;

	if (a1 == -b1)
		return 0;
	else if ((a1 < 0) != (b1 < 0))
	{
		/* On se ramène au cas où a <= 0 et b >= 0 */
		if (a1 <= 0)
		{
			float t = a1;
			a1 = b1;
			b1 = t;
		}
		if (-FLT_MIN - a1 < b1 && a1 < FLT_MIN - b1) 
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

		if (a1 > FLT_MAX - b1)	
			goto overflow;

		if (negative)
		{
			a1 = -a1;
			b1 = -b1;
		}
	}

	return a1 + b1;

underflow:
	ret_value = positive_result ? FLT_MIN : -FLT_MIN;		
overflow:
	errno = ERANGE;
	return ret_value;
}

float secure_sub_f(float const a, float const b)
{
    return secure_add_f(a, -b);
}


float secure_mul_f(float const a, float const b)
{
	int const different_signs = (a < 0) != (b < 0);
	float ret_value = different_signs ? -FLT_MAX : FLT_MAX;

	if (fabsf(b) < 1) 
	{
		if (fabsf(a) < FLT_MIN / fabsf(b))
			goto underflow;
	}
	else
	{
		if (fabsf(a) > FLT_MAX / fabsf(b))
			goto overflow;
	}	

	return a * b;

underflow:
	ret_value = different_signs ? -FLT_MIN : FLT_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}


float secure_div_f(float const a, float const b)
{
	int const different_signs = (a < 0) != (b < 0);
	float ret_value = different_signs ? -FLT_MAX : FLT_MAX;

	if (b == 0)
	{
		errno = EDOM;
		return ret_value;	
	}
	else if (fabsf(b) < 1)
	{
		if (fabsf(a) > FLT_MAX * fabsf(b))
			goto overflow;
	}
	else
	{
		if (fabsf(a) < FLT_MIN * fabsf(b))
			goto underflow;
	}

	return a / b;

underflow:
	ret_value = different_signs ? -FLT_MIN : FLT_MIN;
overflow:
	errno = ERANGE;
	return ret_value;
}