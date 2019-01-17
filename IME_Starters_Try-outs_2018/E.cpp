//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月29日 星期三 16时31分53秒
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

const int MAXN = 1005, INF = 0x3f3f3f3f;

struct edge {
	int from, to;
	ll dist;

	edge() {}
	edge(int u, int v, ll w) : from(u), to(v), dist(w) {}

	bool operator<(const edge &another) const
	{
		return dist < another.dist;
	}
};

int n;
vector<edge> e;
vector<int> g[MAXN];
int fa[MAXN], a[MAXN];

void init()
{
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find_father(int x)
{
	return (x == fa[x] ? x : fa[x] = find_father(fa[x]));
}

ll kruskal()
{
	ll ans = 0;
	sort(e.begin(), e.end());
	init();
	for (int i = 0; i < (int)e.size(); i++) {
		int u = e[i].from, v = e[i].to;
		int p = find_father(u), q = find_father(v);
		if (p != q) {
			fa[q] = p;
			ans += e[i].dist;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	return ans;
}

void dfs(int u, int f)
{
	a[u] = f;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		if (v == f) continue;
		dfs(v, u);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++)
		for (int j = 1; j <= i; j++) {
			ll x;
			scanf("%lld", &x);
			e.push_back(edge(i + 1, j, -x));
		}
	ll ans = -kruskal();
	dfs(1, 0);
	printf("%lld\n", ans);
	for (int i = 2; i <= n; i++) printf("%d\n", a[i]);
	return 0;
}
