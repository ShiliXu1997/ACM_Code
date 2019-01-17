//************************************************************************
// File Name: POJ_1741.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年02月26日 星期一 21时49分18秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10005;

struct edge {
	int to, len;

	edge(int _to, int _len) : to(_to), len(_len) {}
};

int n, k, root, size;
int sz[MAXN], mxson[MAXN], d[MAXN];
bool visited[MAXN];
vector<edge> g[MAXN];
vector<int> dist;

void get_root(int u, int fa)
{
	sz[u] = 1; mxson[u] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].to;
		if (v != fa && !visited[v]) {
			get_root(v, u);
			sz[u] += sz[v];
			mxson[u] = max(mxson[u], sz[v]);
		}
	}
	mxson[u] = max(mxson[u], size - sz[u]);
	if (mxson[u] < mxson[root]) root = u;
}

void get_dist(int u, int fa)
{
	dist.push_back(d[u]);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].to;
		if (v != fa && !visited[v]) {
			d[v] = d[u] + g[u][i].len;
			get_dist(v, u);
		}
	}
}

int cal(int u, int base)
{
    dist.clear();
	d[u] = base;
	get_dist(u, 0);
	sort(dist.begin(), dist.end());
	int ans = 0, l = 0, r = dist.size() - 1;
	while (l < r) {
		if (dist[l] + dist[r] <= k)
			ans += (r - l), l++;
		else
			r--;
	}
	return ans;
}

int work(int u)
{
	visited[u] = true;
	int ans = 0;
	ans += cal(u, 0);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].to;
		if (!visited[v]) {
			ans -= cal(v, g[u][i].len);
			root = 0; size = mxson[0] = sz[v];
			get_root(v, 0);
			ans += work(root);
		}
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	while (scanf("%d %d", &n, &k) == 2 && n != 0 && k != 0) {
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a].push_back(edge(b, c));
			g[b].push_back(edge(a, c));
		}
		int ans = 0;
		root = 0; size = mxson[0] = n;
		memset(visited, false, sizeof(visited));
		get_root(1, 0);
		ans = work(root);
		printf("%d\n", ans);
	}
	return 0;
}
