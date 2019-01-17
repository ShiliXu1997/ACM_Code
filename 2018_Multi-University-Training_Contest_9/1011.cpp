//******************************************************************************
// File Name: 1011.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月20日 星期一 12时33分57秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int t;
ll a, b, c, d;

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

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		ll ans = 0, n = a + b + c + d;
		if (d >= 1) ans = (ans + d * (qpow(2, b, MOD) - 1) % MOD * qpow(2, n - b - d, MOD) % MOD) % MOD;
		if (d >= 2) ans = (ans + (qpow(2, d, MOD) - d - 1) % MOD * qpow(2, n - d, MOD)) % MOD;
		ans = (ans + (qpow(2, c, MOD) - 1) * (qpow(2, b, MOD) - 1 - b) % MOD * qpow(2, a, MOD) % MOD) % MOD;
		ans = (qpow(2, n, MOD) - ans + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
