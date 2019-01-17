//******************************************************************************
// File Name: POJ_2763.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月16日 星期三 16时53分47秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

struct edge {
	int from, to;
	ll dist;

	edge() {}
	edge(int u, int v, ll w) : from(u), to(v), dist(w) {}
};

int n, q, s, tot;
vector<edge> e;
vector<int> g[MAXN];
int fa[MAXN], top[MAXN], deep[MAXN], sz[MAXN], max_son[MAXN], in[MAXN];
int connect[MAXN], id[MAXN];
ll a[MAXN], len[MAXN];

void init()
{
	tot = 0;
	sz[0] = 0;
	memset(a, 0, sizeof(a));
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
}

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, ll num)
{
	while (x <= n) a[x] += num, x += lowbit(x);
}

ll sum(int x)
{
	ll ans = 0;
	while (x) ans += a[x], x -= lowbit(x);
	return ans;
}

void dfs_1(int u, int f, int dpth)
{
	fa[u] = f;
	deep[u] = dpth;
	sz[u] = 1;
	max_son[u] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == f) continue;
		dfs_1(now.to, u, dpth + 1);
		if (sz[max_son[u]] < sz[now.to])
			max_son[u] = now.to, connect[u] = g[u][i];
		sz[u] += sz[now.to];
	}
}

void dfs_2(int u, int tp)
{
	top[u] = tp;
	in[u] = ++tot;
	if (max_son[u]) {
		edge &now = e[connect[u]];
		id[(connect[u] + 2) >> 1] = tot + 1;
		modify(tot + 1, now.dist);
		dfs_2(now.to, tp);
	}
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == fa[u] || now.to == max_son[u]) continue;
		id[(g[u][i] + 2) >> 1] = tot + 1;
		modify(tot + 1, now.dist);
		dfs_2(now.to, now.to);
	}
}

int main()
{
	scanf("%d %d %d", &n, &q, &s);
	init();
	for (int i = 1; i <= n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
		len[i] = w;
	}
	dfs_1(1, 0, 0);
	dfs_2(1, 1);
	while (q--) {
		int mes;
		scanf("%d", &mes);
		if (mes == 0) {
			int t, u, v;
			scanf("%d", &t);
			u = s, v= t;
			ll ans = 0;
			while (top[u] != top[v]) {
				if (deep[top[u]] < deep[top[v]]) swap(u, v);
				ans += sum(in[u]) - sum(in[top[u]] - 1);
				u = fa[top[u]];
			}
			if (deep[u] < deep[v]) swap(u, v);
			if (u != v) ans += sum(in[u]) - sum(in[v]);
			s = t;
			printf("%lld\n", ans);
		}
		if (mes == 1) {
			int p; ll w;
			scanf("%d %lld", &p, &w);
			modify(id[p], w - len[p]);
			len[p] = w;
		}
	}
	return 0;
}
