//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月09日 星期四 15时08分02秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double PI = acos(-1), EPS = 5e-7;

int t;
double a, b;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lf %lf", &a, &b);
		printf("%.6f\n", (2 * b + a * PI) - EPS);
	}
	return 0;
}
