//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月08日 星期六 21时25分19秒
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

const int MOD = 1e9 + 7;

ll n, m;
vector<ll> fac;

ll qpow(ll a, ll b, ll c)
{
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ans;
}

void get_fac(ll x)
{
	fac.clear();
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			fac.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) fac.push_back(x);
}

int main()
{
	ll inv_2 = qpow(2, MOD - 2, MOD);
	ll inv_6 = qpow(6, MOD - 2, MOD);
	while (scanf("%lld %lld", &n, &m) == 2) {
		get_fac(m);
		int sz = fac.size();
		ll ans = (n * (n + 1) % MOD * (2 * n + 1) % MOD * inv_6 % MOD + n * (n + 1) % MOD * inv_2 % MOD) % MOD;
		for (int i = 1; i < (1 << sz); i++) {
			int cnt = __builtin_popcount(i);
			ll t = 1;
			for (int j = 0; j < sz; j++) if (i & (1 << j)) t *= fac[j];
			ll num = n / t;
			ll sum = num * (num + 1) % MOD * inv_2 % MOD * t % MOD;
			sum = (sum + t * t % MOD * num % MOD * (num + 1) % MOD * (2 * num + 1) % MOD * inv_6 % MOD) % MOD;
			if (cnt & 1)
				ans = ((ans - sum) % MOD + MOD) % MOD;
			else
				ans = (ans + sum) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
