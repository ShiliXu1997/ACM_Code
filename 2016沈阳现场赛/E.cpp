//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 05 Nov 2018 05:06:56 PM CST
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
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define x first
#define y second

const int MAXN = 105;

int t, n, m, s, ans, cnt;
vector<int> g[MAXN];
int degree[MAXN], point[MAXN];
bool connect[MAXN][MAXN];

void dfs(int u)
{
    if (cnt == s) {
        ans++;
        return;
    }
    for (auto v: g[u]) {
        if (degree[v] < s - 1) continue;
        bool flag = true;
        for (int j = 1; j <= cnt && flag; j++)
            if (!connect[v][point[j]]) flag = false;
        if (flag) {
            point[++cnt] = v;
            dfs(v);
            cnt--;
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &s);
        for (int i = 1; i <= n; i++) g[i].clear();
        memset(connect, false, sizeof(connect));
        memset(degree, 0, sizeof(degree));
        ans = 0; cnt = 0;
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u > v) swap(u, v);
            degree[u]++;
            degree[v]++;
            connect[u][v] = connect[v][u] = true;
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (degree[i] < s - 1) continue;
            point[++cnt] = i;
            dfs(i);
            cnt--;
        }
        printf("%d\n", ans);
    }
	return 0;
}
