//************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月01日 星期日 14时50分04秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l, r, lc = 0, rc = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (abs(-a[i] - a[i + 1]) <= abs(a[i] - a[i + 1]))
			if (abs(a[i] - a[i + 1]) - abs(-a[i] - a[i + 1]) >= rc) r = i, rc = abs(a[i] - a[i + 1]) - abs(-a[i] - a[i + 1]);	
	}
	for (int i = 2; i <= r; i++) {
		if (abs(-a[i] - a[i - 1]) <= abs(a[i] - a[i - 1]))
			if (abs(a[i] - a[i - 1]) - abs(-a[i] - a[i - 1]) >= lc) l = i, lc = abs(a[i] - a[i - 1]) - abs(-a[i] - a[i - 1]);
	}
	long long ans = abs(-a[l] - a[l - 1]) + abs(-a[r] - a[r + 1]);
	for (int i = 1; i <= l - 2; i++) ans += abs(a[i] - a[i + 1]);
	for (int i = l; i <= r - 1; i++) ans += abs(a[i] - a[i + 1]);
	for (int i = r + 1; i <= n - 1; i++) ans += abs(a[i] - a[i + 1]);
	printf("%lld\n", ans);
	return 0;
}
