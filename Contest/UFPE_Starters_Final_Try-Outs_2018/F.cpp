//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月12日 星期六 19时58分38秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 3e4 + 5;

struct edge {
	int from, to;
	ll dist;

	edge() {}
	edge(int u, int v, ll w) : from(u), to(v), dist(w) {}
};

struct node {
	int u;
	ll d;

	node() {}
	node(int _u, ll _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int n, m, k, p;
ll t;
vector<edge> e;
vector<int> g[MAXN];
priority_queue<node> q;
ll d[MAXN];
bool done[MAXN], is[MAXN];

void add_edge(int from, int to, ll dist)
{
	e.push_back(edge(from, to, dist));
	g[to].push_back(e.size() - 1);
}

void dijkstra(int x)
{
	memset(d, 0x3f, sizeof(d));
	memset(done, false, sizeof(done));
	d[x] = 0;
	q.push(node(x, d[x]));
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.from] > d[u] + now.dist) {
				d[now.from] = d[u] + now.dist;
				q.push(node(now.from, d[now.from]));
			}
		}
	}
}

int main()
{
	scanf("%d %d %lld %d %d", &n, &m, &t, &k, &p);
	memset(is, false, sizeof(is));
	for (int i = 1; i <= p; i++) {
		int x;
		scanf("%d", &x);
		is[x] = true;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf("%d %d %lld", &u, &v, &w);
		add_edge(u, v, w * 60 + (is[v] ? k : 0));
	}
	dijkstra(n);
	if (d[1] <= t * 60)
		printf("%lld\n", d[1]);
	else
		printf("-1\n");
	return 0;
}
