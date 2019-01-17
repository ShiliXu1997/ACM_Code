//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月31日 星期二 21时43分44秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1 << 10, MOD = 1e9 + 7;

int t, n, m;
int cnt[MAXN];
ll f[MAXN], ans[15];

int main()
{
	for (int i = 0; i < MAXN; i++)
		cnt[i] = __builtin_popcount(i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		int all = (1 << n);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		while (m--) {
			char mes[2];
			int u, v;
			scanf("%s %d %d", mes, &u, &v);
			int paigu = (1 << (u - 1)) | (1 << (v - 1));
			if (mes[0] == '+') {
				for (int i = 0; i < all; i++) {
					if (!(i & paigu))
						f[i ^ paigu] = (f[i ^ paigu] + f[i]) % MOD;
				}
			}
			else {
				for (int i = 0; i < all; i++) {
					if (!(i & paigu))
						f[i ^ paigu] = (f[i ^ paigu] - f[i]) % MOD;
				}
			}
			memset(ans, 0, sizeof(ans));
			for (int i = 0; i < all; i++) {
				ans[cnt[i]] = (ans[cnt[i]] + f[i]) % MOD;
			}
			for (int i = 2; i <= n; i += 2)
				printf("%lld%c", (ans[i] % MOD + MOD) % MOD, " \n"[i == n]);
		}
	}
	return 0;
}
