//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月28日 星期三 18时52分13秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 55;
const double INF = 1e9, EPS = 1e-8;

struct edge {
	int from, to;
	double dist;

	edge() {}
	edge(int _from, int _to, double _dist) : from(_from), to(_to), dist(_dist) {}
};

int t, n, m;
vector<edge> e;
vector<int> g[MAXN];
queue<int> q;
double d[MAXN];
int cnt[MAXN];
bool inq[MAXN], visited[MAXN];

void add_edge(int from, int to, double dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

bool spfa(int x)
{
	memset(inq, false, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[x] = 0; q.push(x); inq[x] = true; visited[x] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] > d[u] + now.dist) {
				d[now.to] = d[u] + now.dist;
				if (!inq[now.to]) {
					q.push(now.to);
					inq[now.to] = true;
					visited[now.to] = true;
					if (++cnt[now.to] == n) return true;
				}
			}
		}
	}
	return false;
}

bool check(double x)
{
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < e.size(); i++) e[i].dist -= x;
	bool ans = false;
	for (int i = 1; i <= n && !ans; i++)
		if (!visited[i] && spfa(i)) ans = true;
	for (int i = 0; i < e.size(); i++) e[i].dist += x;
	return ans;
}

void init()
{
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
}

int main()
{
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		scanf("%d %d", &n, &m);
		init();
		int a, b;
		double c, mn = INF, mx = -INF;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %lf", &a, &b, &c);
			add_edge(a, b, c);
			mn = min(mn, c);
			mx = max(mx, c);
		}
		if (!check(mx + 1)) 
			printf("Case #%d: No cycle found.\n", kase);
		else {
			double l = mn, r = mx;
			while (fabs(r - l) > EPS) {
				double mid = (l + r) / 2;
				if (check(mid))
					r = mid;
				else
					l = mid;
			}
			double mid = (l + r) / 2;
			printf("Case #%d: %.2f\n", kase, mid);
		}
	}
	return 0;
}
