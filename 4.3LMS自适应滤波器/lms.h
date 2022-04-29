#pragma once
#include <stdio.h>
#include "gauss.h"
#include "uniform.h"

//��ʶ����������һ����ͷ�ļ���ȫ��д��ǰ����»��ߣ������ļ����еġ�.��Ҳ����»��ߣ��磺stdio.h
//#ifndef _STDIO_H_
//#define _STDIO_H_
//......
//#endif




// x ˫����ʵ��һά���飬����Ϊn�������ź�
//d ˫����ʵ��һά����,����Ϊn����������źš�
//y ˫����ʵ��һά���飬����Ϊn��ʵ������źš�
//n ���ͱ����������źŵĳ��ȡ�
//w ˫����ʵ��һά���飬����Ϊm������Ӧ�˲����ļ�Ȩϵ��
//m ���ͱ���������Ӧ�˲����ĳ���(����һ1)
//mu ˫����ʵ�ͱ������������ӡ�
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


