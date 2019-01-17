//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月01日 星期六 15时00分53秒
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

const int MAXN = 21;

int n;
int a[MAXN], b[MAXN], need[MAXN];
map<int, ll> dp[MAXN];

ll dfs(int i, int j)
{
	if (dp[i].count(j)) return dp[i][j];
	ll &ans = dp[i][j] = 0;
	for (int k = 1; k <= n; k++) {
		if (((j & (1 << (k - 1))) == 0) && ((j & need[k]) == need[k]))
			ans = max(ans, (ll)a[k] * (i + 1) + b[k] + dfs(i + 1, j | (1 << (k - 1))));
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d %d %d", &a[i], &b[i], &s);
		need[i] = 0;
		for (int j = 1; j <= s; j++) {
			int x;
			scanf("%d", &x);
			need[i] ^= (1 << (x - 1));
		}
	}
	printf("%lld\n", dfs(0, 0));
	return 0;
}
