//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月18日 星期三 02时08分33秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5, MOD = 1e9 + 9;

int n, k;
ll a, b;
char s[MAXN];

ll qpow(ll a, ll b)
{
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d %lld %lld %d", &n, &a, &b, &k);
	scanf("%s", s);
	ll sum = 0, inv_a = qpow(a, MOD - 2), q = b * inv_a % MOD, now = 1;
	for (int i = 0; i < k; i++) {
		if (s[i] == '+') sum = (sum + now % MOD) % MOD;
		if (s[i] == '-') sum = (sum - now % MOD) % MOD;
		now = now * q % MOD;
	}
	q = qpow(q, k);
	if (q == 1)
		sum = sum * (n + 1) / k % MOD;
	else {
		sum = sum * (qpow(q, (n + 1) / k) - 1) % MOD;
		sum = sum * qpow(q - 1, MOD - 2) % MOD;
	}
	sum = (sum * qpow(a, n) % MOD + MOD) % MOD;
	printf("%lld\n", sum);
	return 0;
}
