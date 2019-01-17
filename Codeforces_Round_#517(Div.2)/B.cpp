//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 05:57:39 PM CST
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

const int MAXN = 1e5 + 5;

int n;
int a[MAXN], b[MAXN], ans[MAXN];
bool dp[MAXN][4];
int pre[MAXN][4];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) scanf("%d", &b[i]);
    memset(dp, false, sizeof(dp));
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = true;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= 3; j++) {
            if (!dp[i][j]) continue;
            for (int k = 0; k <= 3; k++)
                if ((j | k) == a[i] && (j & k) == b[i]) dp[i + 1][k] = true, pre[i + 1][k] = j;
        }
    }
    bool flag = false;
    for (int i = 0; i <= 3 && !flag; i++) {
        if (dp[n][i]) {
            flag = true;
            printf("YES\n");
            int x = i, pos = n;
            while (pos) {
                ans[pos] = x;
                x = pre[pos][x];
                pos--;
            }
            for (int j = 1; j <= n; j++) printf("%d ", ans[j]);
        }
    }
    if (!flag) printf("NO\n");
	return 0;
}
