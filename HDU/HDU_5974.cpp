//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月25日 星期日 16时10分02秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-6;

int a, b;

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
	while (scanf("%d %d", &a, &b) == 2) {
		double d = a * a - 4 * b * gcd(a, b);
		if (d < 0) {printf("No Solution\n"); continue;}
		d = sqrt(d);
		int c;
		bool flag = false;
		if (fabs(floor(d) - d) < EPS) c = floor(d), flag = true;
		if (fabs(floor(d + 1) - d) < EPS) c = floor(d + 1), flag = true;
		int ans1 = (a + c) / 2, ans2 = (a - c) / 2;
		if (ans1 > ans2) swap(ans1, ans2);
		if (!flag || (a + c % 2 == 1))
			printf("No Solution\n");
		else
			printf("%d %d\n", ans1, ans2);
	}
	return 0;
}

