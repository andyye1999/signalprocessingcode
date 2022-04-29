#ifndef A_H
#define A_H
#include <stdio.h>
double uniform(double a, double b, long int* seed)
{
	//*seed 任意的种子数
	//随机数的值区间:a~b
	double t;
	*seed = 2045 * (*seed) + 1;
	*seed = *seed - (*seed / 1048576) * 1048576;
	t = (*seed) / 1048576.0;
	t = a + (b - a) * t;
	return t;
}

#endif