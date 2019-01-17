//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月21日 星期二 14时00分34秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 706;

int n;
int a[MAXN];
bool dp[MAXN][MAXN][2];
bool g[MAXN][MAXN];

int gcd(int a, int b)
{
	return (!b ? a : gcd(b, a % b));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) g[i][j] = (gcd(a[i], a[j]) != 1);
	memset(dp, false, sizeof(dp));
	for (int l = n; l >= 1; l--) {
		for (int r = l; r <= n; r++) {
			for (int i = l; i <= r; i++) {
				bool ok = (i == l || dp[l][i - 1][0]) && (i == r || dp[i + 1][r][1]);
				if (ok) {
					if (r < n && g[i][r + 1]) dp[l][r][0] = true;
					if (l > 1 && g[l - 1][i]) dp[l][r][1] = true;
				}
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n && !flag; i++) {
		bool ok = (i == 1 || dp[1][i - 1][0]) && (i == n || dp[i + 1][n][1]);
		if (ok) flag = true;
	}
	printf("%s\n", flag ? "Yes" : "No");
	return 0;
}
