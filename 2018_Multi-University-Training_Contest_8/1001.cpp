//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月15日 星期三 13时26分30秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5, MOD = 998244353;

int t, n, m, k;
ll fac[MAXN], facinv[MAXN];

void init()
{
	fac[0] = fac[1] = 1; facinv[0] = facinv[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		facinv[i] = (MOD - MOD / i) * facinv[MOD % i] % MOD;
	}
	for (int i = 2; i < MAXN; i++) facinv[i] = facinv[i] * facinv[i - 1] % MOD;
}

ll C(int n, int m)
{
	return fac[n] * facinv[n - m] % MOD * facinv[m] % MOD;
}

int main()
{
	init();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		if ((ll)(n - 1) * m < k) {
			printf("0\n");
			continue;
		}
		ll ans = C(k + m - 1, m - 1);
		for (int i = 1, now = -1; i <= min(k / n, m); i++, now = -now)
			ans = ((ans + (ll)now * C(m, i) * C(k + m - 1 - i * n, m - 1) % MOD) % MOD + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
