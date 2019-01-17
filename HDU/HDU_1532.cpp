//******************************************************************************
// File Name: HDU_1532.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月06日 星期五 06时33分59秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 205, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow;

	edge() {}
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int n, m;
vector<edge> e;
vector<int> g[MAXN];
int d[MAXN], cur[MAXN];
queue<int> q;

void init()
{
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int f)
{
	e.push_back(edge(u, v, c, f));
	g[u].push_back(e.size() - 1);
}

bool bfs(int s, int t)
{
	while (!q.empty()) q.pop();
	memset(d, 0, sizeof(d));
	d[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++) {
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
	for (int &i = cur[u]; i < g[u].size(); i++) {
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
	freopen("in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) == 2) {
		init();
		while (m--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c, 0);
			add_edge(b, a, 0, 0);
		}
		int ans = dinic(1, n);
		printf("%d\n", ans);
	}
	return 0;
}
