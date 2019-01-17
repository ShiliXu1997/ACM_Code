//************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月01日 星期日 15时57分50秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-5;

double x_1, y_1, r_1, x_2, y_2, r_2;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool good(double rate)
{
	double dx = x_2 - x_1, dy = y_2 - y_1;
	dx *= rate; dy *= rate;
	if (dist(x_1 + dx, y_1 + dy, x_1, y_1) > r_1 && abs(dist(x_1 + dx, y_1 + dy, x_1, y_1) - r_1) > EPS) return false;
	if (dist(x_1 + dx, y_1 + dy, x_2, y_2) > r_2 && abs(dist(x_1 + dx, y_1 + dy, x_2, y_2) - r_2) > EPS) return false;
	return true;
}

bool check(double rate)
{
	double dx = x_2 - x_1, dy = y_2 - y_1;
	dx *= rate; dy *= rate;
	return (dist(x_1 + dx, y_1 + dy, x_1, y_1) < r_1 || abs(dist(x_1 + dx, y_1 + dy, x_1, y_1) - r_1) <= EPS);
}

int main()
{
	scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
	double l = 0, r = 1.0;
	while (!good((l + r) / 2)) {
		double mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	} 
	double mid = (l + r) / 2, ansx = (x_2 - x_1) * mid + x_1, ansy = (y_2 - y_1) * mid + y_1;
	printf("%f %f", ansx, ansy);
	return 0;
}
