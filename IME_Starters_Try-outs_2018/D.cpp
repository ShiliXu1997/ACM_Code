//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月29日 星期三 13时13分05秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, m;
double a[MAXN], h[MAXN];

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, double num)
{
	while (x <= n) {
		a[x] += num;
		x += lowbit(x);
	}
}

double sum(int x)
{
	double ans = 0;
	while (x) {
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 1; i <= n; i++) {
		double x;
		scanf("%lf", &x);
		h[i] = x;
		modify(i, x);
	}
	scanf("%d", &m);
	while (m--) {
		int mes;
		scanf("%d", &mes);
		if (mes == 1) {
			int pos;
			double x;
			scanf("%d %lf", &pos, &x);
			modify(pos, x - h[pos]);
			h[pos] = x;
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r);
			double s = sum(r) - sum(l - 1);
			printf("%.6f\n", s / (r - l + 1));
		}
		
	}
	return 0;
}
