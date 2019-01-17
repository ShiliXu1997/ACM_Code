//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月10日 星期六 20时05分01秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) dp[i][i] = dp[i][i - 1] = 0;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= n - i + 1; j++) {
				dp[j][j + i - 1] = max(dp[j][j + i - 2], dp[j + 1][j + i - 1]);
				dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j + 1][j + i - 2] + (a[j] == a[j + i - 1] ? 1 : 0));
			}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
