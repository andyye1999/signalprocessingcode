#include <stdio.h>
#include "gauss.h"

int main()
{
	int i, j;
	long int s;
	double x, mean, sigma;
	double gauss(double mean, double sigma, long int* s);
	mean = 0.0; sigma = 1.0; s = 13579;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			x = gauss(mean,sigma,&s);
			printf("%13.7f", x);
		}
		printf("\n");
	}
	return 0;
}