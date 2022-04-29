#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "lms.h"

int main01()
{
	int i, m, n;
	long seed;
	double mu, pi, mean, sigma;
	static double d[501], x[501], y[501], w[50];
	FILE* fp;
	pi = 4.0 * atan(1.0);
	mean = 0.0;
	sigma = 1.0;
	seed = 13579l;
	n = 500;
	for (i = 0; i < n; i++) {
		d[i] = sqrt(2.0) * sin(2 * pi * i / 20.0);
		d[i] += gauss(mean, sigma, &seed);
	}
	for (i = 0; i < (n - 1); i++) {
		x[i + 1] = d[i];
	}
	fp = fopen("lmsd.dat", "w");
	for (i = 0; i < n; i++) {
		fprintf(fp, "%d %lf\n", i, d[i]);
	}
	fclose(fp);
	m = 20;
	mu = 0.0005;
	lms(x, d, y, n, w, m, mu);
	printf("自适应滤波器系数\n");
	for (i = 0; i < m; i += 4) {
		printf("%10.7f  %10.7f", w[i], w[i + 1]);
		printf("%10.7f  %10.7f", w[i+2], w[i + 3]);
		printf("\n");
	}
	fp = fopen("lmsy.dat", "w");
	for (i = 0; i < n; i++) {
		fprintf(fp, "%d  %lf\n", i, y[i]);
	}
	fclose(fp);
	return 0;
}