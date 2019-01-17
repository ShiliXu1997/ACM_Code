//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 12时30分25秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int t, n, m, k;

int sgn(double x)
{
	if (fabs(x - 0) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		if (k == n)
			printf("%.3f\n", (double)n / 2);
		else {
			if (sgn(0.5 * m * k - n) >= 0)
				printf("%.3f\n", (double)(n - k) + 0.5 * k);
			else
				printf("%.3f\n", 0.5 * m * k);
		}
	}
	return 0;
}
