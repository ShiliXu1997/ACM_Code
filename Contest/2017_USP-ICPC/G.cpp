//************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 14时11分59秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5, MAXA = 26, INF = 0x3f3f3f3f;

int k;
int cost[MAXA][MAXA];
int dp[MAXA][MAXN];

int main()
{
	scanf("%d", &k);
	for (int i = 0; i < MAXA; i++)
		for (int j = 0; j < MAXA; j++) scanf("%d", &cost[i][j]);
	for (int i = 0; i < MAXA; i++) dp[i][1] = 0;
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j < MAXA; j++) {
			dp[j][i] = INF;
			for (int k = 0; k < MAXA; k++) dp[j][i] = min(dp[j][i], cost[j][k] + dp[k][i - 1]);
		}
	}
	int ans = INF;
	for (int i = 0; i < MAXA; i++) ans = min(ans, dp[i][k]);
	printf("%d", ans);
	return 0;
}
