//************************************************************************
// File Name: W.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月21日 星期三 16时59分33秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 35;

int n, m;
char gr[MAXN][MAXN];
int g[MAXN][MAXN];
unsigned long long dp[MAXN][MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	char s[MAXN];
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) gr[i][j] = s[j];
	}
	bool flag = true;
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= n && flag; i++) {
		for (int j = 1; j <= m && flag; j++) {
			if (gr[i][j] == 'B') {
				for (int l = 1; l <= i; l++)
					for (int c = 1; c <= j; c++) g[l][c] = 1;
			}
			if (gr[i][j] == 'R') {
				for (int l = i; l <= n; l++)
					for (int c = j; c <= m; c++) {
						if (gr[l][c] == 'B') flag = false;
						g[l][c] = 2;
					}
			}
		}
	}
	if (!flag) {
		printf("0");
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		int st = -1, ed;
		for (int j = 1; j <= m; j++) {
			if (!g[i][j] && st == -1) st = j - 1;
			if (st != -1)  {
				if (g[i][j]) {
					ed = j - 1;
					break;
				}
				if (j == m) ed = j;
			}
		}
		if (st != -1) {
			for (int j = st; j <= ed; j++) {
				for (int k = j; k <= m; k++) dp[i][j] += dp[i - 1][k];
				if (!dp[i][j]) dp[i][j] = 1;
			}
		}
		else {
			for (int j = 0; j <= m; j++) dp[i][m] += dp[i - 1][j];
		}
	}
	unsigned long long ans = 0;
	for (int l = n; l >= 1; l--) {
		for (int i = 0; i <= m; i++) ans += dp[l][i];
		if (ans) break;
	}
	printf("%llu", (ans > 0 ? ans : 1));
	return 0;
}
