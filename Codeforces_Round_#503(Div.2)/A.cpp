//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月11日 星期六 21时54分54秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <cmath>
using namespace std;
typedef long long ll;

int n, h, k, a, b;

int main()
{
	scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
	while (k--) {
		ll ans = 0;
		ll ta, fa, tb, fb;
		pair<ll, ll> p, q;
		scanf("%lld %lld %lld %lld", &ta, &fa, &tb, &fb);
		p = make_pair(ta, fa);
		q = make_pair(tb, fb);
		if (p > q) swap(p, q);
		if (p.first == q.first)
			ans = llabs(p.second - q.second);
		else {
			ans += llabs(p.first - q.first);
			if (p.second >= b) ans += llabs(b - p.second), p.second = b;
			if (p.second < a) ans += llabs(a - p.second), p.second = a;
			if (q.second >= b) ans += llabs(b - q.second), q.second = b;
			if (q.second < a) ans += llabs(a - q.second), q.second = a;
			ans += llabs(p.second - q.second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
