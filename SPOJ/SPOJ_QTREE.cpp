//******************************************************************************
// File Name: SPOJ_QTREE.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月14日 星期一 22时03分01秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;

struct edge {
	int from, to, dist;

	edge() {}
	edge(int _u, int _v, int _w) : from(_u), to(_v), dist(_w) {}
};

struct segment {
	int l, r, mx;
};

int t, n, tot;
char s[10];
segment tree[MAXN << 2];
int fa[MAXN], top[MAXN], sz[MAXN], deep[MAXN], max_son[MAXN], in[MAXN], id[MAXN], a[MAXN], connect[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

void init()
{
	tot = 0;
	sz[0] = 0;
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
}

void dfs_1(int u, int f, int dpth)
{
	fa[u] = f;
	deep[u] = dpth;
	max_son[u] = 0;
	sz[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == f) continue;
		dfs_1(now.to, u, dpth + 1);
		if (sz[max_son[u]] < sz[now.to])
			max_son[u] = now.to, connect[u] = g[u][i];
		sz[u] += sz[now.to];
	}
}

void dfs_2(int u, int tp)
{
	in[u] = ++tot;
	top[u] = tp;
	if (max_son[u]) {
		id[(connect[u] + 2) >> 1] = tot + 1;
		a[tot + 1] = e[connect[u]].dist;
		dfs_2(max_son[u], tp);
	}
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == fa[u] || now.to == max_son[u]) continue;
		id[(g[u][i] + 2) >> 1] = tot + 1;
		a[tot + 1] = now.dist;
		dfs_2(now.to, now.to);
	}
}

void build(int left, int right, int root)
{
	tree[root].l = left;
	tree[root].r = right;
	int mid = (left + right) >> 1;
	if (left == right) {
		tree[root].mx = a[mid];
		return;
	}
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	tree[root].mx = max(tree[root << 1].mx, tree[root << 1 | 1].mx);
}

void modify(int pos, int num, int root)
{
	if (tree[root].l == tree[root].r) {
		tree[root].mx = num;
		return;
	}
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (pos <= mid) modify(pos, num, root << 1);
	if (pos >= mid + 1) modify(pos, num, root << 1 | 1);
	tree[root].mx = max(tree[root << 1].mx, tree[root << 1 | 1].mx);
}

int query(int left, int right, int root)
{
	if (left <= tree[root].l && tree[root].r <= right)	
		return tree[root].mx;
	int ans = -INF, mid = (tree[root].l + tree[root].r) >> 1;
	if (left <= mid) ans = max(ans, query(left, right, root << 1));
	if (right >= mid + 1) ans = max(ans, query(left, right, root << 1 | 1));
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n - 1; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);
		}
		dfs_1(1, 0, 0);
		dfs_2(1, 1);
		build(1, n, 1);
		while (scanf("%s", s) == 1 && s[0] != 'D') {
			int a, b;
			scanf("%d %d", &a, &b);
			if (s[0] == 'Q') {
				int ans = -INF;
				while (top[a] != top[b]) {
					if (deep[top[a]] < deep[top[b]]) swap(a, b);
					ans = max(ans, query(in[top[a]], in[a], 1));
					a = fa[top[a]];
				}
				if (deep[a] < deep[b]) swap(a, b);
				if (a != b) ans = max(ans, query(in[max_son[b]], in[a], 1));
				printf("%d\n", ans);
			}
			if (s[0] == 'C') modify(id[a], b, 1);
		}
	}
	return 0;
}
