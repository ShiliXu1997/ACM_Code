//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月20日 星期一 14时11分17秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 81;

int t, n, m, k;
ll dp[MAXN][MAXN][MAXN * MAXN];

ll dfs(int x, int y, int z)
{
	if (dp[x][y][z] != -1) return dp[x][y][z];
	ll &ans = dp[x][y][z];
	ans = 0;
	if (x < n) ans = (ans + (n - x) * y * dfs(x + 1, y, z + 1)) % k;
	if (y < m) ans = (ans + (m - y) * x * dfs(x, y + 1, z + 1)) % k;
	if (x * y > z) ans = (ans + (x * y - z) * dfs(x, y, z + 1)) % k;
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		memset(dp, 0xff, sizeof(dp));
		dp[n][m][n * m] = 1;
		ll ans = n * m * dfs(1, 1, 1) % k;
		printf("%lld\n", ans);
	}
	return 0;
}
