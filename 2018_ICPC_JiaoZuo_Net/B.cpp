//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 15 Sep 2018 01:45:59 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int t, n, m, k;

map<ll, ll> dp[MAXN][6];
ll num[MAXN];
char sign[6];

ll dfs(int p, int q, ll now)
{
    if (dp[p][q].count(now)) return dp[p][q][now];
    if (q == m + 1) return now;
    ll &ans = dp[p][q][now] = -INF;
    for (int i = p; i <= n - (m - q); i++) {
        if (sign[q] == '+') ans = max(ans, dfs(i + 1, q + 1, now + num[i]));
        if (sign[q] == '-') ans = max(ans, dfs(i + 1, q + 1, now - num[i]));
        if (sign[q] == '*') ans = max(ans, dfs(i + 1, q + 1, now * num[i]));
        if (sign[q] == '/') ans = max(ans, dfs(i + 1, q + 1, now / num[i]));
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
        scanf("%s", sign);
        for (int i = m; i >= 1; i--) sign[i] = sign[i - 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) dp[i][j].clear();
        // ll ans = dfs(1, 1, (ll)k);
        // printf("%lld\n", ans);
    }
	return 0;
}
