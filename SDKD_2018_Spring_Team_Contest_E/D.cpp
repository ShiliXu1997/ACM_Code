//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 21时30分15秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 55, MOD = 1e9 + 7;

struct edge {
	int from, to, dist;

	edge(){}
	edge(int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}
};

struct node {
	int u, d;

	node() {}
	node(int _u, int _d) : u(_u), d(_d) {}
	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int n;
char s[MAXN];
vector<edge> e;
vector<int> g[MAXN];
vector<int> pre[MAXN];
int d[MAXN];
bool done[MAXN];
priority_queue<node> q;

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

int dijkstra(int x)
{
	memset(d, 0x3f, sizeof(d));
	memset(done, false, sizeof(done));
	d[x] = 0;
	q.push(node(x, 0));
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] > d[u] + now.dist) {
				d[now.to] = d[u] + now.dist;
				q.push(node(now.to, d[now.to]));
				pre[now.to].clear();
			}
			if (d[now.to] == d[u] + now.dist) pre[now.to].push_back(g[u][i]);
		}
	}
}

void init()
{
	e.clear();
	for (int i = 0; i < n; i++) g[i].clear(), pre[i].clear();
}

int main()
{
	while (scanf("%d", &n) == 1) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			for (int j = 1; j <= n; j++)
				if (s[j - 1] != '0') add_edge(i - 1, j - 1, s[j - 1] - '0');
		}
		dijkstra(0);
		long long ans = 1;
		for (int i = 1; i < n; i++) ans = ans * pre[i].size() % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
