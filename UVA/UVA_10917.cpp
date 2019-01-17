//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月27日 星期二 20时55分29秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
	int from, to;
	long long dist;

	edge() {}
	edge (int _from, int _to, long long _dist) : from(_from), to(_to), dist(_dist) {}
};

struct node {
	int u;
	long long d;

	node() {}
	node(int _u, long long _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int n, m;
vector<edge> e;
vector<int> g[MAXN];
long long d[MAXN], visited[MAXN];
bool done[MAXN];
priority_queue<node> q;

void add_edge(int from, int to, long long dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

void dijkstra(int x)
{
	memset(done, false, sizeof(done));
	memset(d, 0x3f, sizeof(d));
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
			}
		}
	}
}

void init()
{
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
	memset(visited, 0xff, sizeof(visited));
}

long long dfs(int u)
{
	if (u == 2) return 1;
	if (visited[u] != -1) return visited[u];
	visited[u] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (d[now.to] < d[u]) visited[u] += dfs(now.to);
	}
	return visited[u];
}

int main()
{
	while (scanf("%d", &n) == 1 && n != 0) {
		init();
		scanf("%d", &m);
		int a, b;
		long long c;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %lld", &a, &b, &c);
			add_edge(a, b, c);
			add_edge(b, a, c);
		}
		dijkstra(2);
		printf("%lld\n", dfs(1));
	}
	return 0;
}
