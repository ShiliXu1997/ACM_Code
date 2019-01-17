//******************************************************************************
// File Name: 1005.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月13日 星期一 15时11分13秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

int t, m, n, mod;
vector<int> prime;
bool done[MAXN];
ll mobius[MAXN], phi[MAXN], inv[MAXN];

void get_mobius_phi(int n)
{
	memset(done, false, sizeof(done));
	memset(mobius, 0, sizeof(mobius));
	mobius[1] = phi[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!done[i]) {
			prime.push_back(i);
			mobius[i] = -1;
			phi[i] = i - 1;
		}
		for (int j = 0; j < (int)prime.size() && (ll)i * prime[j] < n; j++) {
			done[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else {
				mobius[i * prime[j]] = -mobius[i];
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}

ll solve(int p, int q)
{
	ll ans = 0;
	for (int i = 1; i <= min(p, q); i++)
		ans = (ans + (ll)mobius[i] * (p / i) * (q / i)) % mod;
	return ans;
}

int main()
{
	get_mobius_phi(MAXN);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &m, &n, &mod);
		if (n >= m) swap(n, m);
		inv[1] = 1;
		for (int i = 2; i <= n; i++)
			inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans = (ans + (ll)i * solve(n / i, m / i) % mod * inv[phi[i]] % mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
