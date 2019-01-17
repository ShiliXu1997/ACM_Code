//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月30日 星期四 12时44分29秒
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

int n;
ll a[MAXN], b[MAXN];
map<ll, int> cnt;

bool check()
{
	ll x = 0;
	for (int i = 1; i <= n && x <= 3; i++) if (b[i] != a[i]) x++;
	return (x <= 3);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 2; i <= n; i++) {
		ll x = a[i] - a[i - 1];
		if (!cnt.count(x))
			cnt[x] = 1;
		else
			cnt[x]++;
	}
	bool flag = false;
	for (map<ll, int>::iterator it = cnt.begin(); it != cnt.end() && !flag; ++it) {
		ll cha = it->first;
		for (int i = 1; i <= 4 && !flag; i++) {
			b[i] = a[i];
			for (int j = i + 1; j <= n; j++) b[j] = b[j - 1] + cha;
			for (int j = i - 1; j >= 1; j--) b[j] = b[j + 1] - cha;
			if (check()) flag = true;
		}
	}
	for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
	return 0;
}
