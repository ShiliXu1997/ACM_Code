//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 09:30:05 PM CST
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

const int MAXN = 1e5 + 5, MOD = 998244353;

int n;
int a[MAXN];
ll dp[201][MAXN];

ll dfs(int last, int pos)
{
    if (dp[last][pos] != -1) return dp[last][pos];
    if (pos == n + 1) return 1;
    ll &ans = dp[last][pos] = 0;
    if (a[pos] != -1) {
        if (last < a[pos] && a[pos + 1] != -1 && a[pos + 1] < a[pos]) return ans = 0;
        return ans = dfs(a[pos], pos + 1);
    }
    int mx = last ? last : 200;
    if (a[pos + 1] != -1) mx = max(mx, a[pos + 1]);
    for (int i = 1; i <= mx; i++) ans += dfs(i, pos + 1), ans %= MOD;
    return ans;
}

int main()
{
    scanf("%d", &n);
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 1;
    memset(dp, 0xff, sizeof(dp));
    for (int i = 1; i <= n; i++)
        if (a[i] == -1) {
            ans = dfs(a[i - 1], i);
            break;
        }
    for (int i = 1; i <= n; i++)
        if (a[i - 1] != -1 && a[i] != -1 && a[i + 1] != -1 && a[i - 1] < a[i] && a[i + 1] < a[i]) ans = 0;
    printf("%lld\n", ans);
	return 0;
}
