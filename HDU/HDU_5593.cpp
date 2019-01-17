//******************************************************************************
// File Name: HDU_5593.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月11日 星期六 11时14分07秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

int t, n, k, a, b;
int fa[MAXN], sum[11];
int dp[MAXN][11];

int get(int u)
{
	int ans = 0;
	memset(sum, 0, sizeof(sum));
	for (int i = 0, son = 0; u && i <= k; son = u, u = fa[u], i++) {
		sum[i]++;
		for (int j = 1; j <= k - i; j++) sum[i + j] += dp[u][j] - dp[son][j - 1];
	}
	for (int i = 0; i <= k; i++) ans += sum[i];
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &n, &k, &a, &b);
		memset(dp, 0, sizeof(dp));
		fa[1] = 0;
		dp[1][0] = 1;
		for (int i = 2; i <= n; i++) {
			fa[i] = ((ll)a * i + b) % (i - 1) + 1;
			for (int u = i, j = 0; u && j <= k; u = fa[u], j++) dp[u][j]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans ^= get(i);
		printf("%d\n", ans);
	}
	return 0;
}
