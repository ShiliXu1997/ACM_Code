//******************************************************************************
// File Name: HDU_3501.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 11时08分29秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll n;
vector<int> p;

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

void get_factors(ll n)
{
	p.clear();
	for (int i = 2; (ll)i * i <= n; i++) {
		if (n % i == 0) {
			p.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) p.push_back(n);
}

vector<int> get_all(int bg, int i)
{
	vector<int> ans;
	if (i == 1) {
		for (int j = bg; j <= p.size(); j++) ans.push_back(p[j - 1]);
		return ans;
	}
	for (int j = bg; j <= p.size() - i + 1; j++) {
		vector<int> a = get_all(j + 1, i - 1);
		for (int k = 0; k < a.size(); k++) ans.push_back(p[j - 1] * a[k]);
	}
	return ans;
}

int main()
{
	ll inv_2 = qpow(2, MOD - 2, MOD);
	while (scanf("%lld", &n) == 1 && n) {
		if (n == 1) {
			printf("0\n");
			continue;
		}
		get_factors(n);
		ll ans = 0;
		for (int i = 1; i <= p.size(); i++) {
			vector<int> a = get_all(1, i);
			for (int j = 0; j < a.size(); j++) {
				ans = (ans + ((ll)(i & 1 ? 1 : -1) * ((ll)a[j] * (1 + n / a[j]) % MOD * (n / a[j]) % MOD * inv_2 % MOD)) % MOD + MOD) % MOD;
			}
		}
		ans = (ans - n + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
