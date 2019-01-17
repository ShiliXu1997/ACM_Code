//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月09日 星期日 12时28分43秒
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

int n, q;
ll a[MAXN], c[MAXN], d[MAXN];

int lowbit(int x)
{
	return (x & -x);
}

void modify_c(int x, ll num)
{
	while (x <= n) {
		c[x] += num;
		x += lowbit(x);
	}
}

ll sum_c(int x)
{
	ll ans = 0;
	while (x) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

void modify_d(int x, ll num)
{
	while (x <= n) {
		d[x] += num;
		x += lowbit(x);
	}
}

ll sum_d(int x)
{
	ll ans = 0;
	while (x) {
		ans += d[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &q);
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		modify_c(i, a[i]);
		modify_d(i, a[i] * (n - i + 1));
	}
	while (q--) {
		int mes, l, r;
		scanf("%d %d %d", &mes, &l, &r);
		if (mes == 1) {
			ll ans = (sum_d(r) - sum_d(l - 1)) - ((sum_c(r) - sum_c(l - 1)) * (n - r));
			printf("%lld\n", ans);
		}
		else {
			modify_c(l, (ll)r - a[l]);
			modify_d(l, (ll)(n - l + 1) * (r - a[l]));
			a[l] = (ll)r;
		}
	}
	return 0;
}
