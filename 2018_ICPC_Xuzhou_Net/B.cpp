//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月09日 星期日 16时35分51秒
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

const int MAXN = 1005, MAXM = 205;

int n, m, l, k;
int x[MAXN], y[MAXN], z[MAXN];
int dp[MAXN][MAXM][2];

int dfs(int p, int m, int now)
{
	if (p > n) return m;
	//puts("-------");
	if (dp[p][m + 100][now] != -1) return dp[p][m + 100][now];
	int a, b, c;
	int &ans = dp[p][m + 100][now];
	if (!now) {
		ans = -100;
		if (x[p]) a = dfs(p + 1, m + x[p], now ^ 1), ans = max(ans, a);
		if (y[p]) b = dfs(p + 1, m - y[p], now ^ 1), ans = max(ans, b);
		if (z[p]) c = dfs(p + 1, -m, now ^ 1), ans = max(ans, c);
		ans = min(ans, 100);
	}
	else {
		ans = 100;
		if (x[p]) a = dfs(p + 1, m + x[p], now ^ 1), ans = min(ans, a);
		if (y[p]) b = dfs(p + 1, m - y[p], now ^ 1), ans = min(ans, b);
		if (z[p]) c = dfs(p + 1, -m, now ^ 1), ans = min(ans, c);
		ans = max(ans, -100);
	}
	//printf("%d %d\n", p, ans);
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &k, &l);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
	memset(dp, 0xff, sizeof(dp));
	int ans = dfs(1, m, 0);
	//printf("%d\n", ans);
	if (ans >= k)
		printf("Good Ending\n");
	else
	if (ans <= l)
		printf("Bad Ending\n");
	else
		printf("Normal Ending\n");
	return 0;
}
