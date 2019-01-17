//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月11日 星期日 12时49分53秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

int m, n, x, y, xx, yy;
double r;

int main()
{
	scanf("%d %d %lf", &m, &n, &r);
	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	r /= (double)n;
	double ans = (double)INF;
	for (int i = 0; i <= max(y, yy); i++)
		ans = min(ans, PI * r * i * abs(x - xx) / m + r * (abs(y - i) + abs(yy - i)));
	printf("%f", ans);
	return 0;
}
