//******************************************************************************
// File Name: 1012.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月22日 星期三 15时06分29秒
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

const int MAXN = 500, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow, cost;

	edge() {}
	edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

int t, n, m, k, w;
vector<edge> e;
vector<int> g[MAXN];
int d[MAXN], a[MAXN], p[MAXN], st[MAXN], ed[MAXN], tp[MAXN];
bool inq[MAXN];
queue<int> q;

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int w)
{
	e.push_back(edge(u, v, c, 0, w));
	e.push_back(edge(v, u, 0, 0, -w));
	g[u].push_back(e.size() - 2);
	g[v].push_back(e.size() - 1);
}

bool spfa(int s, int t, int &flow, int &cost)
{
	memset(d, 0x3f, sizeof(d));
	memset(inq, false, sizeof(inq));
	d[s] = 0; q.push(s); inq[s] = true;
	a[s] = INF;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = 0; i < (int)g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (now.cap - now.flow > 0 && d[now.to] > d[u] + now.cost) {
				a[now.to] = min(a[u], now.cap - now.flow);
				p[now.to] = g[u][i];
				d[now.to] = d[u] + now.cost;
				if (!inq[now.to]) {
					q.push(now.to);
					inq[now.to] = true;
				}
			}
		}
	}
	if (d[t] == INF) return false;
	for (int i = t; i != s; i = e[p[i]].from) {
		e[p[i]].flow += a[t];
		e[p[i] ^ 1].flow -= a[t];
	}
	flow += a[t];
	cost += d[t] * a[t];
	return true;
}

int min_cost_max_flow(int s, int t, int	&cost)
{
	int ans = 0;
	cost = 0;
	while (spfa(s, t, ans, cost));
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d %d %d %d", &x, &m, &k, &w);
		n = 2 * m + 2;
		init();
		add_edge(0, 1, k, 0);
		for (int i = 1; i <= m; i++) {
			int get;
			scanf("%d %d %d %d", &st[i], &ed[i], &get, &tp[i]);
			add_edge(2 * i,  2 * i + 1, 1, -get);
			add_edge(1, 2 * i, 1, 0);
			add_edge(2 * i + 1, n, 1, 0);
		}
		for (int i = 1; i <= m - 1; i++) {
			for (int j = i + 1; j <= m; j++) {
				if (ed[i] <= st[j]) {
					if (tp[i] == tp[j])
						add_edge(2 * i + 1, 2 * j, 1, w);
					else
						add_edge(2 * i + 1, 2 * j, 1, 0);
				}
				if (ed[j] <= st[i]) {
					if (tp[j] == tp[i])
						add_edge(2 * j + 1, 2 * i, 1, w);
					else
						add_edge(2 * j + 1, 2 * i, 1, 0);
				}

			}
		}
		int ans;
		min_cost_max_flow(0, n, ans);
		printf("%d\n", -ans);
	}
	return 0;
}
