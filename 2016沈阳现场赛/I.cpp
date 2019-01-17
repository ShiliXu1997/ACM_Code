//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 04 Nov 2018 11:23:31 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define x first
#define y second

const int MAXN = 1e5 + 5;

int t, n, p;
int q[MAXN];
vector<pii> g[MAXN];
ll dp[MAXN], dist[MAXN];
stack<int> s;

void init()
{
    for (int i = 1; i <= n; i++) g[i].clear();
}

ll sqr(ll x)
{
    return x * x;
}

ll get_up(int i, int j)
{
    return (dp[i] + sqr(dist[i])) - (dp[j] + sqr(dist[j]));
}

ll get_down(int i, int j)
{
    return dist[i] - dist[j];
}

void dfs(int u, int fa, int st, int ed)
{
    dp[u] = sqr(dist[u]);
    int head = st, tail = ed;
    while (head + 1 < tail && get_up(q[head + 1], q[head]) <= 2 * dist[u] * get_down(q[head + 1], q[head])) head++;
    dp[u] = min(dp[u], dp[q[head]] + sqr(dist[u] - dist[q[head]]) + p);
    while (head + 1 < tail && get_up(u, q[tail - 1]) * get_down(q[tail - 1], q[tail - 2]) <= get_up(q[tail - 1], q[tail - 2]) * get_down(u, q[tail - 1])) tail--;
    q[tail++] = u;
    for (pii now: g[u]) {
        if (now.x == fa) continue;
        dist[now.x] = dist[u] + now.y;
        dfs(now.x, u, head, tail);
    }
    tail--;
    while (!s.empty()) {
        int v = s.top(); s.pop();
        q[tail++] = v;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &p);
        init();
        for (int i = 1; i <= n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(pii(v, w));
            g[v].push_back(pii(u, w));
        }
        dp[1] = dist[1] = 0;
        q[0] = 1;
        for (pii now: g[1]) {
            dist[now.x] = now.y;
            dfs(now.x, 1, 0, 1);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        printf("%lld\n", ans);
    }
	return 0;
}
