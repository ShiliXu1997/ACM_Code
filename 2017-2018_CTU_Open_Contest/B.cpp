//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月11日 星期日 09时58分17秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
const double EPS = 1e-6;

int n, f;
int c[MAXN];

bool check_last(double t)
{
	double remain = 0;
	for (int i = 1; i <= n - 1; i++) {
		remain = remain + t * f - (double)c[i];
		if (remain < 0 || fabs(remain) < EPS) remain = 0;
	}
	return (fabs(remain + t * f - (double)c[n]) < 0 || remain + t * f - (double)c[n] > 0);
}

bool check_all(double t)
{
	bool flag = true;
	double remain = 0;
	for (int i = 1; i <= n && flag; i++) {
		remain = remain + t * f - (double)c[i];
		if (remain < 0) flag = false;
	}
	return flag;
}

int main()
{
	while (scanf("%d %d", &n, &f) == 2) {
		double sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]), sum += (double)c[i];
		double l = 0, r = (double)c[n] / f, mid, time_last, time_all;
		while (r >= l && r - l >= EPS) {
			mid = (l + r) / 2;
			if (check_last(mid))
				r = mid;
			else
				l = mid;
		}
		time_last = (l + r) / 2;
		l = 0; r = (sum) / f;
		while (r >= l && r - l >= EPS) {
			mid = (l + r) / 2;
			if (check_all(mid))
				r = mid;
			else
				l = mid;
		}
		time_all = (l + r) / 2;
		printf("%.6f %.6f\n", time_last, time_all);
	}

	return 0;
}
