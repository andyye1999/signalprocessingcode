
void fft(float *x, float *y, short n, short sign)
{
	short i, j, k, l, m, n1, n2;
	float c, c1, e, s, s1, t, tr, ti;

	//xʵ�� y�鲿

	for (j = i = 1; i<32; i++)
	{
		m = i; 
		j = 2 * j;
		if (j == n) break;	 //m=log2n
	}
	// ��λ����
	for (n1 = n - 1, j = 0, i = 0; i<n1; i++)
	{
		if (i<j)  //��λ�������Ȼ�򣬽��洢��Ԫ�����ݻ���
		{
			tr = x[j];
			ti = y[j];
			x[j] = x[i];
			y[j] = y[i];
			x[i] = tr;
			y[i] = ti;
		}
		k = n / 2;
		while (k<(j + 1))
		{
			j = j - k;
			k = k / 2;
		}
		j = j + k;
	}
	for (n1 = l = 1; l <= m; l++)  // ��һ�� ÿһ���ĵ������� ��m=log2n�� 
	{
		n1 = 2 * n1;    //��m�� 2^m
		n2 = n1 / 2;    // 2^m-1
		e = 3.1415926535897932384626433832795f / n2;
		c = 1.0;
		s = 0.0;
		c1 = cos(e);
		s1 = -sign*sin(e);
		for (j = 0; j<n2; j++)   //ÿһ��ĵ�������     �����롱L=2^m-1  
		{
			for (i = j; i<n; i += n1)   //1����������
			{
				k = i + n2;
				tr = c*x[k] - s*y[k];
				ti = c*y[k] + s*x[k];
				x[k] = x[i] - tr;
				y[k] = y[i] - ti;
				x[i] = x[i] + tr;
				y[i] = y[i] + ti;
			}
			t = c;
			c = c*c1 - s*s1;
			s = t*s1 + s*c1;
		}
	}
	if (sign == -1)
	{
		for (i = 0; i<n; i++) { x[i] /= n; y[i] /= n; }
	}
}