//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月18日 星期六 23时02分02秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

ll n, q;

int main()
{
	scanf("%lld %lld", &n, &q);
	while (q--) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		if ((x + y) & 1) {
			ll st = (ll)(ceil((double)(n * n) / 2) + EPS) + 1, ans;
			ans = (n * (x - 1) + y + 1) / 2 + st - 1;
			printf("%lld\n", ans);
		}
		else {
			ll st = 1, ans;
			ans = (n * (x - 1) + y + 1) / 2 + st - 1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
