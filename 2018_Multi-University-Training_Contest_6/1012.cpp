//******************************************************************************
// File Name: 1012.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月08日 星期三 13时29分18秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double PI = acos(-1), EPS = 1e-8, G = 9.8;

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

int t;
double x, y, a, b;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lf %lf %lf %lf", &a, &b, &x, &y);
		double phi = atan(b / a), theta = 0;
		double yp = -b / a * x;
		double v = sqrt(G * 2 * (y - yp));
		y = yp;
		int cnt = 0;
		while (true) {
			if (sgn(x) > 0) break;
			cnt++;
			double beta = PI / 2 - phi * 2 - theta;
			double vx = v * cos(beta), vy = v * sin(beta);
			double ti = 2 * (vx * b + vy * a) / G / a;
			double hx = vx * ti, hy = -vy * ti + 0.5 * G * ti * ti;
			x += hx, y -= hy;
			v = sqrt(G * 2 * hy + v * v);
			vy = sqrt(v * v - vx * vx);
			theta = atan(vx / vy);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
