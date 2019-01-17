//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 13时36分27秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m, x;
int a[MAXN], b[MAXN];

int main()
{
	freopen("deposits.in", "r", stdin);
	freopen("deposits.out", "w", stdout);
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		a[x]++;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		b[x]++;
	}
	long long ans = 0;
	for (int i = 1; i < MAXN; i++)
		if (b[i]) {
			for (int j = 1; (long long)j * i < MAXN; j++)
				if (a[j * i]) ans += (long long)a[j * i] * b[i];
		}
	printf("%lld\n", ans);
	return 0;
}
