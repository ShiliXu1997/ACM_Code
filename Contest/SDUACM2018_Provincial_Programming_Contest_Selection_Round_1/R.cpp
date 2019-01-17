//************************************************************************
// File Name: R.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月26日 星期一 16时25分18秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 200;
const double EPS = 1e-8, PI = acos(-1);

int n;
double x, p;
double l[MAXN], r[MAXN], v[MAXN];

bool check(double a)
{
	double v1 = p * sin(a), v2 = p * cos(a);
	double h = 0, sum_t = 0, all_t = x / v2;
	for (int i = 1; i <= n; i++) {
		double t = (r[i] - l[i]) / v2;
		h += t * (v1 + v[i]);
		sum_t += t;
	}
	all_t = all_t - sum_t;
	if (fabs(all_t) > EPS) h += v1 * all_t;
	return (h > 0 || fabs(h) < EPS);
}

int main()
{
	scanf("%d %lf %lf", &n, &x, &p);
	for (int i = 1; i <= n; i++)
		scanf("%lf %lf %lf", &l[i], &r[i], &v[i]);
	double left = -PI / 2 , right = PI / 2;
	while (fabs(right - left) > EPS) {
		double mid = (left + right) / 2;
		if (check(mid))
			right = mid;
		else
			left = mid;
	}
	double mid = (left + right) / 2;
	if (fabs(mid + PI / 2) < EPS || fabs(mid - PI / 2) < EPS)
		printf("Too hard");
	else {
		double v2 = p * cos(mid), ans = x / v2;
		printf("%.3f", ans);
	}
	return 0;
}
