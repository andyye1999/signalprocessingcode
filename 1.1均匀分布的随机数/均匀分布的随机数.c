#include <stdio.h>
#include "uniform.h"

int main()
{
	double a, b, x;
	int i, j;
	long int s;
	double uniform(double, double, long int*);
	a = 0.0; b = 1.0; s = 13579;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			x = uniform(a, b, &s);
			printf("%13.7f", x);
		}
		printf("\n");
	}
}