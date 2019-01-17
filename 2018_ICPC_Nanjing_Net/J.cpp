//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月01日 星期六 12时40分56秒
//******************************************************************************

#include <stdio.h>
#include <string.h>
typedef long long ll;

const int MAXN = 2e7 + 1;

int t, n, cnt;
int prime[MAXN], f[MAXN];
ll sum[MAXN];
bool done[MAXN];

void init(ll n)
{
	for (int i = 2, j = 8; j <= n; ++i, j = i * i * i) {
		int k = j;
		while (k <= n) {
			done[k] = true;
			k += j;
		}
	}
}

void euler(ll n)
{
	memset(done, false, sizeof(done));
	init(n);
	cnt = 0;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!done[i]) {
			prime[++cnt] = i;
			f[i] = 2;
		}
		for (int j = 1; j <= cnt && (ll)i * prime[j] <= n; ++j) {
			int x = i * prime[j];
			if (done[x]) continue;
			done[x] = true;
			if (i % prime[j] == 0) {
				if (i == prime[j])
					f[x] = 1;
				else
					f[x] = f[i / prime[j]];
				break;
			}
			else
				f[x] = f[i] << 1;
		}	
	}
}

int main()
{
	euler(MAXN - 1);
	sum[0] = 0;
	for (int i = 1; i <= MAXN - 1; ++i)
		sum[i] = sum[i - 1] + f[i];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", sum[n]);
	}
	return 0;
}
