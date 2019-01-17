//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月19日 星期日 21时47分15秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

struct p {
	ll a, b;

	bool operator<(const p &another) const
	{
		if (a == another.a) return b < another.b;
		return a < another.a;
	}
};

int n, cnt;
p dui[MAXN];
int prime[MAXN];

bool check(ll x)
{
	for (int i = 1; i <= n; i++)
		if (dui[i].a % x != 0 && dui[i].b % x != 0) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &dui[i].a, &dui[i].b);
		if (dui[i].a > dui[i].b) swap(dui[i].a, dui[i].b);
	}
	sort(dui + 1, dui + 1 + n);
	int cnt = 0;
	ll now = dui[1].a;
	for (int i = 2; (ll)i * i <= now; i++) {
		if (now % i == 0) {
			prime[++cnt] = i;
			while (now % i == 0) now /= i;
		}
	}
	if (now > 1) prime[++cnt] = now;
	now = dui[1].b;
	for (int i = 2; (ll)i * i <= now; i++) {
		if (now % i == 0) {
			prime[++cnt] = i;
			while (now % i == 0) now /= i;
		}
	}
	if (now > 1) prime[++cnt] = now;
	sort(prime + 1, prime + 1 + cnt);
	cnt = unique(prime + 1, prime + 1 + cnt) - prime - 1;
	bool flag = false;
	ll ans = -1;
	if (!flag) {
		for (int i = 1; i <= cnt && !flag; i++) {
			if (check(prime[i])) {
				flag = true;
				ans = prime[i];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
