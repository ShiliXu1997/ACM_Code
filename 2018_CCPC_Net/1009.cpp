//******************************************************************************
// File Name: 1009.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月25日 星期六 13时23分21秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;

struct edge{
	int from, to;
	ll dist;

	edge() {}
	edge(int u, int v, ll w) : from(u), to(v), dist(w) {}
};

int n;
vector<edge> e;
vector<int> g[MAXN];
ll sum[MAXN], sz[MAXN], fac[MAXN];
ll ans;

void init()
{
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, ll d)
{
	e.push_back(edge(u, v, d));
	g[u].push_back(e.size() - 1);
}

void dfs_1(int u, int fa)
{
	sz[u] = 1;
	for (int i = 0; i < (int)g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == fa) continue;
		dfs_1(now.to, u);
		sz[u] += sz[now.to];
	}
}

void dfs_2(int u, int fa)
{
	sum[u] = 0;
	for (int i = 0; i < (int)g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == fa) continue;
		dfs_2(now.to, u);
		sum[u] = (sum[u] + sum[now.to] + sz[now.to] * now.dist) % MOD;
		ans = (ans + (sz[u] - sz[now.to] - 1) * (sum[now.to] + now.dist * sz[now.to])) % MOD;
	}
	ans = (ans + sum[u]) % MOD;
}

void get_fac()
{
	fac[1] = 1;
	for (int i = 2; i < MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	get_fac();
	while (scanf("%d", &n) == 1) {
		init();
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			ll d;
			scanf("%d %d %lld", &u, &v, &d);
			add_edge(u, v, d);
		}
		dfs_1(1, 0);
		ans = 0;
		dfs_2(1, 0);
		ans = ans * 2 % MOD * (n - 1) % MOD * fac[n - 2] % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
