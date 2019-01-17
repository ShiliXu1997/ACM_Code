//******************************************************************************
// File Name: HDU_5988.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月18日 星期五 22时00分30秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 105;
const double INF = 1e17, EPS = 1e-8;

struct edge {
	int from, to, cap, flow;
	double cost;

	edge() {}
	edge(int u, int v, int c, int f, double w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

int t, n, m;
vector<edge> e;
vector<int> g[MAXN];
queue<int> q;
int a[MAXN], p[MAXN];
double d[MAXN];
bool inq[MAXN];

void init()
{
	e.clear();
	for (int i = 0; i <= n + 1; i++) g[i].clear();
}

void add_edge(int u, int v, int c, double w)
{
	e.push_back(edge(u, v, c, 0, w));
	e.push_back(edge(v, u, 0, 0, -w));
	g[u].push_back(e.size() - 2);
	g[v].push_back(e.size() - 1);
}

bool spfa(int s, int t, int &flow, double &cost)
{
	for (int i = 0; i <= n + 1; i++) d[i] = INF;
	memset(inq, false, sizeof(inq));
	d[s] = 0; q.push(s); inq[s] = true;
	a[s] = 0x3f3f3f3f;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (now.cap - now.flow > 0 && d[now.to] > d[u] + now.cost + EPS) {
				a[now.to] = min(a[u], now.cap - now.flow);
				d[now.to] = d[u] + now.cost;
				p[now.to] = g[u][i];
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

int min_cost_max_flow(int s, int t, double &cost)
{
	int ans = 0;
	cost = 0;
	while (spfa(s, t, ans, cost));
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		init();
		for (int i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a - b > 0) add_edge(0, i, a - b, 0);
			if (b - a > 0) add_edge(i, n + 1, b - a, 0);
		}
		while (m--) {
			int u, v, c;
			double p;
			scanf("%d %d %d %lf", &u, &v, &c, &p);
			if (c > 0) add_edge(u, v, 1, 0);
			if (c - 1 > 0) add_edge(u, v, c - 1, -log(1 - p));
		}
		double ans;
		min_cost_max_flow(0, n + 1, ans);
		ans = 1.0 - exp(-ans);
		printf("%.2f\n", ans);
	}
	return 0;
}
