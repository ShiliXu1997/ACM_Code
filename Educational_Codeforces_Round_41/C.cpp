//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 22时42分14秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105, INF = 0x3f3f3f3f;

int n;
int g[5][MAXN][MAXN];
int dp[5][2];
char s[MAXN];

int main()
{
	scanf("%d", &n);
	int kase = 4;
	for (int t = 1; t <= kase; t++) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			for (int j = 1; j <= n; j++) g[t][i][j] = s[j - 1] - '0';
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int t = 1; t <= kase; t++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (!((i + j) & 1))
					dp[t][1] += (g[t][i][j] == 0), dp[t][0] += (g[t][i][j] == 1);
				else
					dp[t][1] += (g[t][i][j] == 1), dp[t][0] += (g[t][i][j] == 0);
			}
	}
	int ans = min(INF, dp[1][1] + dp[2][1] + dp[3][0] + dp[4][0]);
	ans = min(ans, dp[1][1] + dp[2][0] + dp[3][1] +dp[4][0]);
	ans = min(ans, dp[1][1] + dp[2][0] + dp[3][0] +dp[4][1]);
	ans = min(ans, dp[1][0] + dp[2][1] + dp[3][1] +dp[4][0]);
	ans = min(ans, dp[1][0] + dp[2][1] + dp[3][0] +dp[4][1]);
	ans = min(ans, dp[1][0] + dp[2][0] + dp[3][1] +dp[4][1]);
	printf("%d\n", ans);
	return 0;
}
