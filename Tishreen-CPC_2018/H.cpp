//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 04:20:24 PM CST
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

int t, n, a, b;
vector<int> g[MAXN];
int fa[MAXN], sz[MAXN];

void init()
{
    for (int i = 1; i <= n; i++) g[i].clear();
}

void dfs(int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &a, &b);
        init();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(a, 0);
        ll ans = (ll)sz[b] * n;
        while (fa[b]) {
            ll add = (ll)(sz[fa[b]] - sz[b]) * (n - sz[b]);
            ans += add;
            b = fa[b];
        }
        ans = (ll)n * n - ans;
        printf("%lld\n", ans);
    }
	return 0;
}
