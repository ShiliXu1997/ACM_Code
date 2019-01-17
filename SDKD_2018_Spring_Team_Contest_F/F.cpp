//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 11时22分37秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
long long a[MAXN];

int lowbit(int x)
{
	return (x & -x);
}

long long sum(int x)
{
	long long ans = 0;
	while (x) {
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i & 1) continue;
		if (sum(i - 1) - sum(i - lowbit(i)) != 0) a[i - 1] -= (sum(i - 1) - sum(i - lowbit(i)));
	}
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	return 0;
}
