//******************************************************************************
// File Name: POJ_2516.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月13日 星期五 14时08分09秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 5100, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow, cost;

	edge() {}
	edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

int shopkeepers, providers, kinds, n;
vector<edge> e;
vector<int> g[MAXN];
int a[MAXN], p[MAXN], d[MAXN], out[55], in[55];
int need[55][55], give[55][55];
bool inq[MAXN];
queue<int> q;

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int f, int w)
{
	e.push_back(edge(u, v, c, f, w));
	g[u].push_back(e.size() - 1);
}

bool spfa(int s, int t, int &flow, int &cost)
{
	for (int i = 0; i <= n; i++) d[i] = INF;
	memset(inq, false, sizeof(inq));
	d[s] = 0; q.push(s); inq[s] = true;
	a[s] = INF;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (now.cap - now.flow > 0 && d[now.to] > d[u] + now.cost) {
				d[now.to] = d[u] + now.cost;
				a[now.to] = min(a[u], now.cap - now.flow);
				p[now.to] = g[u][i];
				if (!inq[now.to]) {
					q.push(now.to);
					inq[now.to] = false;
				}
			}
		}
	}
	if (d[t] == INF) return false;
	for (int i = t; i != s; i = e[p[i]].from) {
		e[p[i]].flow += a[t];
		e[p[i] ^ 1].flow -= a[t];
	}
	flow +=a[t];
	cost += d[t] * a[t];
	return true;
}

int min_cost_max_flow(int s, int t, int &cost)
{
	int ans = 0;
	cost = 0;
	while (spfa(s, t, ans, cost));
	return ans;
}

int main()
{
	while (scanf("%d %d %d", &shopkeepers, &providers, &kinds) == 3) {
		if (shopkeepers == 0 && providers == 0 && kinds == 0) break;
		n = shopkeepers + providers + 1;
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		for (int i = 1; i <= shopkeepers; i++)
			for (int j = 1; j <= kinds; j++) scanf("%d", &need[i][j]), in[j] += need[i][j];
		for (int i = 1; i <= providers; i++)
			for (int j = 1; j <= kinds; j++) scanf("%d", &give[i][j]), out[j] += give[i][j];
		bool flag = true;
		for (int i = 1; i <= kinds; i++)
			if (out[i] < in[i]) flag = false;
		int ans = 0;
		for (int k = 1; k <= kinds; k++) {
			init();
			for (int i = 1; i <= shopkeepers; i++) {
				add_edge(providers + i, n, need[i][k], 0, 0);
				add_edge(n, providers + i, 0, 0, 0);
			}
			for (int i = 1; i <= providers; i++) {
				add_edge(0, i, give[i][k], 0, 0);
				add_edge(i, 0, 0, 0, 0);
			}
			for (int j = 1; j <= shopkeepers; j++)
				for (int m = 1; m <= providers; m++) {
					int x;
					scanf("%d", &x);
					add_edge(m, providers + j, INF, 0, x);
					add_edge(providers + j, m, 0, 0, -x);
				}
			if (!flag) continue;
			int cost;
			min_cost_max_flow(0, n, cost);
			ans += cost;
		}
		if (!flag) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}
