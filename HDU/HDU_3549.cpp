//******************************************************************************
// File Name: HDU_3549.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月17日 星期四 22时52分17秒
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

int t, n, m;
vector<edge> e;
vector<int> g[MAXN];
int p[MAXN], a[MAXN];
queue<int> q;

void init()
{
	e.clear();
	for (int i = 1; i<= n; i++) g[i].clear();
}

void add_edge(int from, int to, int cap, int flow)
{
	e.push_back(edge(from, to, cap, flow));
	g[from].push_back(e.size() - 1);
}

int edmond_karp(int s, int t)
{
	int ans = 0;
	while (true) {
		memset(a, 0, sizeof(a));
		a[s] = INF;
		while (!q.empty()) q.pop();
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < g[u].size(); i++) {
				edge &now = e[g[u][i]];
				if (!a[now.to] && now.cap - now.flow > 0) {
					p[now.to] = g[u][i];
					a[now.to] = min(a[u], now.cap - now.flow);
					q.push(now.to);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;
		for (int i = t; i != s; i = e[p[i]].from) {
			e[p[i]].flow += a[t];
			e[p[i] ^ 1].flow -= a[t];
		}
		ans += a[t];
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		scanf("%d %d", &n, &m);
		init();
		while (m--) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			add_edge(u, v, c, 0);
			add_edge(v, u, 0, 0);
		}
		int ans = edmond_karp(1, n);
		printf("Case %d: %d\n", kase, ans);
	}
	return 0;
}
