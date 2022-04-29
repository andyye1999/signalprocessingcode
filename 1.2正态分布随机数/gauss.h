#ifndef A_H
#define A_H
#include <stdio.h>
#include "uniform.h"

//高斯分布
double gauss(double mean, double sigma, long int* s) {
	int i;
	double x, y;
	double uniform();
	for (x = 0, i = 0; i < 12; i++) {
		x += uniform(0.0, 1.0, s);
	}
	x = x - 6.0;
	y = mean + x * sigma;
	return y;
}

#endif