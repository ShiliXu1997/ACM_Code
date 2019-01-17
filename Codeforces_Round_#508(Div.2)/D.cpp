//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月07日 星期五 00时24分20秒
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

const int MAXN = 5e5 + 5;

int n;
ll a[MAXN];

bool check()
{
	bool z = true, f = true;
	for (int i = 1; i <= n && z;i ++) if (a[i] < 0) z = false;
	for (int i = 1; i <= n && f;i ++) if (a[i] > 0) f = false;
	return z || f;
}

int main()
{
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ans += llabs(a[i]);
	if (n == 1) {
		printf("%lld\n", a[1]);
		return 0;
	}
	if (check()) {
		ll mn = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) mn = min(mn, llabs(a[i]));
		ans -= mn * 2;
	}
	printf("%lld\n", ans);
	return 0;
}
