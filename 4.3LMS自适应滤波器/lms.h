#pragma once
#include <stdio.h>
#include "gauss.h"
#include "uniform.h"

//标识的命名规则一般是头文件名全大写，前后加下划线，并把文件名中的“.”也变成下划线，如：stdio.h
//#ifndef _STDIO_H_
//#define _STDIO_H_
//......
//#endif




// x 双精度实型一维数组，长度为n。输入信号
//d 双精度实型一维数组,长度为n。理想输出信号。
//y 双精度实型一维数组，长度为n。实际输出信号。
//n 整型变量。输入信号的长度。
//w 双精度实型一维数组，长度为m。自适应滤波器的加权系数
//m 整型变量。自适应滤波器的长度(阶数一1)
//mu 双精度实型变量。收敛因子。
void lms(x, d, y, n, w, m, mu)
int m, n;
double mu, d[], x[], y[], w[];
{
	int i, k;
	double e;
	for (i = 0; i < m; i++){
		w[i] = 0.0;
	}
	for (k = 0; k < m; k++){
		y[k] = 0.0;
		for (i = 0; i <= k; i++){
			y[k] += x[k - i] * w[i];
		}
		e = d[k] - y[k];
		for (i = 0; i <= k; i++){
			w[i] += 2.0 * mu * e * x[k - i];
		}
	}
	for (k = m; k < n; k++) {
		y[k] = 0.0;
		for (i = 0; i < m; i++) {
			y[k] += x[k - i] * w[i];
		}
		e = d[k] - y[k];
		for (i = 0; i < m; i++) {
			w[i] += 2.0 * mu * e * x[k - i];
		}
	}
}


