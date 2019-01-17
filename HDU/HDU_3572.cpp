//******************************************************************************
// File Name: HDU_3572.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月08日 星期日 21时11分03秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 1005, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow;

	edge() {}
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int t, n, machine, task;
vector<edge> e;
vector<int> g[MAXN];
queue<int> q;
int d[MAXN], cur[MAXN];

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
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
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		scanf("%d %d", &task, &machine);
		n = task + 501;
		init();
		int all = 0;
		for (int i = 1; i <= task; i++) {
			int p, st, ed;
			scanf("%d %d %d", &p, &st, &ed);
			all += p;
			add_edge(0, i, p, 0);
			add_edge(i, 0, 0, 0);
			for (int j = task + st; j <= task + ed; j++) {
				add_edge(i, j, 1, 0);
				add_edge(j, i, 0, 0);
			}
		}
		for (int j = task + 1; j <= task + 500; j++) {
			add_edge(j, task + 501, machine, 0);
			add_edge(task + 501, j, 0, 0);
		}
		int max_flow = dinic(0, task + 501);
		bool flag = (max_flow == all);
		printf("Case %d: %s\n\n", kase, (flag ? "Yes" : "No"));
	}
	return 0;
}
