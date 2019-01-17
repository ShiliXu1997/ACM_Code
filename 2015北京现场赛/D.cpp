//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 07 Nov 2018 01:30:46 PM CST
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

const int MAXN = 505, INF = 0x3f3f3f3f;

struct edge {
    int from, to, cap, flow;

    edge() {}
    edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int t, n, m, s;
vector<edge> e;
vector<int> g[MAXN * 2];
int d[MAXN * 2], cur[MAXN * 2];
queue<int> q;

void init()
{
    e.clear();
    for (int i = 0; i <= 2 * n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int f)
{
    e.push_back(edge(u, v, c, f));
    g[u].push_back(e.size() - 1);
}

bool bfs(int s, int t)
{
    memset(d, 0, sizeof(d));
    d[s] = 1; q.push(s); 
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            edge &now = e[g[u][i]];
            if (d[now.to] || now.cap - now.flow == 0) continue;
            d[now.to] = d[u] + 1;
            q.push(now.to);
        }
    }
    return (d[t] != 0);
}

int dfs(int u, int t, int f)
{
    if (u == t || f == 0) return f;
    int ans = 0, add;
    for (int &i = cur[u]; i < (int)g[u].size(); i++) {
        edge &now = e[g[u][i]];
        if (d[now.to] == d[u] + 1 && (add = dfs(now.to, t, min(f, now.cap - now.flow))) > 0) {
            e[g[u][i]].flow += add;
            e[g[u][i] ^ 1].flow -= add;
            ans += add;
            f -= add;
            if (f == 0) break;
        }
    }
    return ans;
}

int dinic(int s, int t)
{
    int ans = 0;
    while (bfs(s, t)) {
        memset(cur, 0, sizeof(cur));
        ans += dfs(s, t, INF);
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &s);
        init();
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u + n, v, w, 0);
            add_edge(v, u + n, 0, 0);
        }
        for (int i = 1; i <= n; i++) {
            int w;
            scanf("%d", &w);
            add_edge(0, i, w, 0);
            add_edge(i, 0, 0, 0);
        }
        for (int i = 1; i <= n; i++) {
            int w;
            scanf("%d", &w);
            add_edge(i, i + n, w, 0);
            add_edge(i + n, i, 0, 0);
        }
        int ans = dinic(0, s + n);
        printf("%d\n", ans);
    }
	return 0;
}
