//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 06 Oct 2018 09:45:58 AM CST
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

const int MAXN = 45, MAXM = 1 << 20;

int t, n, m;
ll dp[MAXN][MAXM];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d", &n, &m);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < MAXM; j++) dp[i][j] = dp[i - 1][j];
            for (int j = 0; j < MAXM; j++) dp[i][j] +=  dp[i - 1][j ^ x];
        }
        ll ans = 0;
        for (int i = m; i < MAXM; i++) ans += dp[n][i];
        printf("Case #%d: %lld\n", kase, ans);
    }
	return 0;
}
