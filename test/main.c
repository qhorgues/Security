
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <secure_input.h>
#include <secure_arithmetic.h>
#include <math.h>

int main(void)
{
    printf("%.55lf, (%s)\n", M_PI, strerror(errno));
}