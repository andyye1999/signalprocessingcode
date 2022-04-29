#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "lms.h"

int main() {
	int i, m, n, j;
	long seed;
	double mu, pi, mean, sigma, yn, dn,en;
	double d[501] = { 0 };
	double x[501] = { 0 };
	double y[501] = { 0 };
	double w[50] = { 0 };
	pi = 4.0 * atan(1.0);
	mean = 0.0;
	sigma = 1.0;
	seed = 13579l;
	n = 500;
	for (i = 0; i < (n - 1); i++) {
		x[i + 1] = d[i];
	}
	m = 20;
	mu = 0.0005;
	for (i = 0; i < n; i++) {
		d[i] = sqrt(2.0) * sin(2 * pi * i / 20.0);
		d[i] += gauss(mean, sigma, &seed);
	}
	for (j = 1; j < n + 1; j++) {
		for (i = n - 1; i > 0; i--) {
			x[i] = x[i - 1];
		}
		x[0] = d[j - 1];
		for (yn = i = 0; i < m - 1; i++) {
			yn += w[i] * x[i];
		}
		en = d[j-1] - yn;
		for (i = 0; i <= m; i++) {
			w[i] += 2.0 * mu * en * x[j - i];
		}
	}
	printf("自适应滤波器系数\n");
	for (i = 0; i < m; i += 4) {
		printf("%10.7f  %10.7f", w[i], w[i + 1]);
		printf("%10.7f  %10.7f", w[i + 2], w[i + 3]);
		printf("\n");
	}
	return 0;
}