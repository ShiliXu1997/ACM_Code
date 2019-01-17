//******************************************************************************
// File Name: M.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 27 Sep 2018 07:28:42 PM CST
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

int n;
int a[55];
int dp[55][2];

int dfs(int pos, int tp)
{
    if (dp[pos][tp] != -1) return dp[pos][tp];
    int &ans = dp[pos][tp] = 0;
    if (!tp) {
        for (int i = pos + 1; i <= n; i++)
            if (a[i] > a[pos]) ans = max(ans, 1 + dfs(i, 1));
    }
    else {
        for (int i = pos + 1; i <= n; i++)
            if (a[i] < a[pos]) ans = max(ans, 1 + dfs(i, 0));
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mx = 1;
    memset(dp, 0xff, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        mx = max(mx, 1 + dfs(1, 0));
        mx = max(mx, 1 + dfs(1, 1));
    }
    printf("%d\n", mx);
	return 0;
}
