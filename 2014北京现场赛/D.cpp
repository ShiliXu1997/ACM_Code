//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 05 Oct 2018 01:59:06 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 205;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int t, n;
ll b[MAXN];
ll dp[MAXN][MAXN][MAXN];
ll fuck[MAXN][MAXN];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d", &n);
        ll sum = 0, x;
        for (int i = 1; i <= n; i++) scanf("%lld", &x), sum += x;
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        b[0] = b[n + 1] = 0;
        memset(dp, 0, sizeof(dp));
        memset(fuck, 0, sizeof(fuck));
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                fuck[i][j] = INF;
                for (int k = i; k <= j; k++) dp[i][j][k] = INF;
            }
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                for (int k = i; k <= j; k++) {
                    dp[i][j][k] = min(dp[i][j][k], fuck[i][k - 1] + fuck[k + 1][j] + b[i - 1] + b[j + 1]);
                    fuck[i][j] = min(fuck[i][j], dp[i][j][k]);
                }
            }
        }
        ll ans = INF;
        for (int i = 1; i <= n; i++) ans = min(ans, sum + dp[1][n][i]);
        printf("Case #%d: %lld\n", kase, ans);
    }
	return 0;
}
