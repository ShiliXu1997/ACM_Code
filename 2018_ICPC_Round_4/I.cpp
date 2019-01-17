//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 13时32分37秒
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

const int MAXN = 502, MAXM = 52;

int n, m, r;
ll a[MAXN];
ll dp[MAXN][MAXM][MAXM];

ll dfs(int p, int now, int last)
{
	if (now == m) return 0;
	if (p > n) return -0x3f3f3f3f;
	if (dp[p][now][last] != -1) return dp[p][now][last];
	if (last == r) return dfs(p + 1, now, 0);
	ll &ans = dp[p][now][last] = 0;
	ans = max(ans, (ll)(last + 1) * a[p] + dfs(p + 1, now + 1, last + 1));
	ans = max(ans, dfs(p + 1, now, 0));
	return ans;
}

bool check()
{
	int cnt = 0, last = 0;
	for (int i = 1; i <= n; i++) {
		if (last < r) {
			last++;
			cnt++;
		}
		else
			last = 0;
	}
		return cnt >= m;
}

int main()
{
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (!check()) {
		printf("-1\n");
		return 0;
	}
	memset(dp, 0xff, sizeof(dp));
	ll ans = dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
