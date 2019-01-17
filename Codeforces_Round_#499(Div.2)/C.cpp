//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月27日 星期五 10时36分44秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
const double EPS =1e-8;

int n, m;
int a[MAXN], b[MAXN];

int sgn(double x)
{
	return (x > 0 ? 1 : -1);
}

bool check(double now)
{
	double w = now + m;
	for (int i = 1; i <= n; i++) {
		int nxt = i % n + 1;
		double use = w / a[i];
		if (sgn(use - now) <= 0) 
			w -= use, now -= use;
		else
			return false;
		use = w / b[nxt];
		if (sgn(use - now) <= 0)
			w -= use, now -= use;
		else
			return false;
	}
	return true;
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		double l = 0.000000, r = 1e9 + EPS;
		while (sgn(fabs(r - l) - 1e-6) >= 0) {
			double mid = (r + l) / 2;
			if (check(mid))
				r = mid;
			else
				l = mid;
		}
		double ans = r;
		if (check(ans))
			printf("%.8f\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
