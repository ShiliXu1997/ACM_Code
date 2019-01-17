//************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月17日 星期六 14时06分34秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 + 5;

struct rob {
	int a, t;

	bool operator<(const rob &another) const
	{
		return a > another.a;
	}
};

int n;
int v[MAXN];
rob r[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &r[i].a, &r[i].t);
	double df = 0, mx = 0;
	v[0] = 0;
	for (int i = 2; i <= n; i++) v[i] = v[i - 1] + r[i - 1].a * r[i - 1].t;
	for (int i = 1; i <= n; i++) df += 0.5 * r[i].a * r[i].t * r[i].t + v[i] * r[i].t;
	sort(r + 1, r + 1 + n);
	v[0] = 0;
	for (int i = 2; i <= n; i++) v[i] = v[i - 1] + r[i - 1].a * r[i - 1].t;
	for (int i = 1; i <= n; i++) mx += 0.5 * r[i].a * r[i].t * r[i].t + v[i] * r[i].t;
	printf("%.1f", mx - df);
	return 0;
}
