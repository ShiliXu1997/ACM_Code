//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 09:02:17 PM CST
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

const int MOD = 1e9 + 7;

int t, n;
ll dp[105][130];

ll dfs(int remain, int state)
{
    if (!remain) return (state != 0);
    ll &ans = dp[remain][state];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= remain; i++) {
        ans += dfs(remain - i, state ^ i);
        ans %= MOD;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(dp, 0xff, sizeof(dp));
        ll ans = dfs(n, 0);
        printf("%lld\n", ans);
    }
	return 0;
}
