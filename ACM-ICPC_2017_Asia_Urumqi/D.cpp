//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 14时14分14秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int t;

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
	//C(n, 2) + C(n, 4) + 1
	ll inv_2 = qpow(2, MOD - 2, MOD), inv_24 = qpow(24, MOD - 2, MOD);
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		ll n, n1, n2, n3;
		scanf("%lld", &n);
		n1 = n - 1, n2 = n - 2, n3 = n - 3;
		printf("Case #%d: ", kase);
		if (n <= 3) {
			if (n == 1) printf("1\n");
			if (n == 2) printf("2\n");
			if (n == 3) printf("4\n");
			continue;
		}
		n %= MOD; n1 %= MOD; n2 %= MOD; n3 %= MOD;
		ll ans = 1;
		ans = (ans + (n * n1 % MOD) * inv_2 % MOD) % MOD;
		ans = (ans + (n * n1 % MOD * n2 % MOD * n3 % MOD) * inv_24 % MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
