#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535
#define ORD2 5
#define NUM 20000

const double b[ORD2] = { 0.009974726636333, -0.03833394460209,     0.05676259683, -0.03833394460209,
   0.009974726636333 };
const double a[ORD2] = { 1,   -3.849826046791,    5.688203849557,   -3.816962873623,
	 0.9830011607069 };

int main()
{
	long i, k;
	double vv, x[ORD2], y[ORD2];
	FILE* fq, * fr;

	for (k = 0; k < ORD2; k++) x[k] = y[k] = 0;

	fopen_s(&fq, "work1.txt", "r");//读方波 100000点数，幅值为10000
	fopen_s(&fr, "work2.txt", "w");//写滤出的正弦波
	//IIR滤波器
	for (i = 0; i < NUM; i++)
	{
		for (k = ORD2 - 1; k > 0; k--) y[k] = y[k - 1];
		for (k = ORD2 - 1; k > 0; k--) x[k] = x[k - 1];
		fscanf_s(fq, "%lf", &x[0]);
		for (vv = x[0] * b[0], k = 1; k < ORD2; k++) vv += x[k] * b[k] - y[k] * a[k];
		y[0] = vv;

		fprintf(fr, "%d\n", (short)vv);
	}
	fclose(fr);
	fclose(fq);

	int low, high, N = 800; //需要周期的整数点数
	double w, xn, xn2, Asin, Acos, Ws, Ps, Wn, Pn, SNR, SNR1, SNR2, P, W;
	Ws = Wn = W = 0;
	w = 2 * PI * 330 / 8000;
	fopen_s(&fr, "work2.txt", "r");
	for (i = 0; i < 10 * N; i++) fscanf_s(fr, "%lf", &xn);
	for (Asin = Acos = i = 0; i < N; i++) {
		fscanf_s(fr, "%lf", &xn);
		Asin += xn * cos(w * i);
		Acos += xn * sin(w * i);
	}
	fclose(fr);
	Asin = Asin * 2 / N;
	Acos = Acos * 2 / N;

	fopen_s(&fr, "work2.txt", "r");
	for (i = 0; i < 10 * N; i++) fscanf_s(fr, "%lf", &xn);
	for (Ps = Pn = i = 0; i < N; i++) {
		xn2 = Asin * cos(w * i) + Acos * sin(w * i);
		Ps += xn2 * xn2;
		fscanf_s(fr, "%lf", &xn);
		Pn += (xn - xn2) * (xn - xn2);
	}
	fclose(fr);
	SNR = 10 * log10(Ps / Pn);
	printf("SNR = %lf\n", SNR);
	return 0;
}