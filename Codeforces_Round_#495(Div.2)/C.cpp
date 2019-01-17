//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月06日 星期五 01时22分59秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;
int a[MAXN], cnt[MAXN], tot[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	memset(cnt, 0, sizeof(cnt));
	memset(tot, 0, sizeof(tot));
	for (int i = n; i >= 1; i--) {
		tot[i] = tot[i + 1];
		cnt[a[i]]++;
		if (cnt[a[i]] == 1) tot[i]++;
	}
	memset(cnt, 0, sizeof(cnt));
	ll ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		cnt[a[i]]++;
		if (cnt[a[i]] == 1) ans += tot[i + 1];
	}
	printf("%lld\n", ans);
	return 0;
}
