//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月29日 星期四 18时03分19秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 505, INF = 0x3f3f3f3f;

struct edge {
	int from, to, dist;

	edge() {} 
	edge(int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}
};

int n, m;
vector<edge> e;
vector<int> g[MAXN];
long long d[MAXN];
int cnt[MAXN];
bool inq[MAXN];
queue<int> q;

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

bool spfa(int x)
{
	memset(cnt, 0, sizeof(cnt));
	memset(d, 0x3f, sizeof(d));
	memset(inq, false, sizeof(inq));
	d[x] = 0; q.push(x); inq[x] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] > d[u] + now.dist) {
				d[now.to] = d[u] + now.dist;
				if (!inq[now.to]) {
					q.push(now.to);
					inq[now.to] = true;
					if (++cnt[now.to] == n) return true;
				}
			}
		}
	}
	return false;
}

bool check(int x)
{
	for (int i = 0; i < e.size(); i++) e[i].dist -= x;
	bool ans = spfa(0);
	for (int i = 0; i < e.size(); i++) e[i].dist += x;
	return ans;
}

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		init();
		int a, b, c, mx = -INF;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c);
			mx = max(mx, c);
		}
		for (int i = 1; i <= n; i++) add_edge(0, i, 0);
		if (check(1)) {
			printf("No Solution\n");
			continue;
		}
		if (!check(mx)) {
			printf("Infinite\n");
			continue;
		}
		int l = 1, r = mx, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid))
				r = mid - 1;
			else {
				ans = mid;
				l = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
