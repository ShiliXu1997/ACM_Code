//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月05日 星期三 21时05分35秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1001, MAXM = 251, MOD = 1e9 + 7;

int n, t, cnt;
int q[MAXN], x[MAXN], now[MAXN * MAXM];
int dp[MAXN * MAXM][MAXM];

int dfs(int p, int remain)
{
	if (p > cnt) return 1;
	if (dp[p][remain] != -1) return dp[p][remain];
	int &ans = dp[p][remain] = 0;
	if (now[p] == now[p + 1])
		ans += dfs(p + 1, remain), ans %= MOD;
	else
		ans += dfs(p + 1, q[now[p + 1]] - x[now[p + 1]]), ans %= MOD;
	if (remain >= 1) {
		if (now[p] == now[p + t + 1])
			ans += dfs(p + t + 1, remain - 1), ans %= MOD;
		else
			ans += dfs(p + t + 1, q[now[p + t + 1]] - x[now[p + t + 1]]), ans %= MOD;
	}
	return ans;
}

int main()
{
	freopen("kebab.in", "r", stdin);
	freopen("kebab.out", "w", stdout);
	scanf("%d %d", &n, &t);
	cnt = 0;
	memset(now, 0, sizeof(now));
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &q[i], &x[i]);
		for (int j = 1; j <= q[i]; j++) now[++cnt] = i;
	}
	memset(dp, 0xff, sizeof(dp));
	int ans = dfs(1, q[1] - x[1]);
	printf("%d\n", ans);
	return 0;
}
