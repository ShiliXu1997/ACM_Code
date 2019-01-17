//******************************************************************************
// File Name: HYSBZ.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月16日 星期三 20时09分19秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

struct edge {
	int from, to;

	edge() {}
	edge(int u, int v) : from(u), to(v) {}
};

struct segment {
	int l, r;
	int lx, rx, cnt, mark;
};

int n, m, tot;
vector<edge> e;
vector<int> g[MAXN];
segment tree[MAXN << 2];
int fa[MAXN], top[MAXN], deep[MAXN], sz[MAXN], max_son[MAXN], in[MAXN];
int id[MAXN], connect[MAXN], a[MAXN];

void add_edge(int u, int v)
{
	e.push_back(edge(u, v));
	g[u].push_back(e.size() - 1);
}

void dfs_1(int u, int f, int d)
{
	fa[u] = f;
	deep[u] = d;
	sz[u] = 1;
	max_son[u] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == f) continue;
		dfs_1(now.to, u, d + 1);
		if (sz[max_son[u]] < sz[now.to]) max_son[u] = now.to;
		sz[u] += sz[now.to];
	}
}

void dfs_2(int u, int tp)
{
	top[u] = tp;
	in[u] = ++tot;
	id[tot] = u;
	if (max_son[u]) dfs_2(max_son[u], tp);
	for (int i = 0; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (now.to == fa[u] || now.to == max_son[u]) continue;
		dfs_2(now.to, now.to);
	}
}

void push_up(int root)
{
	tree[root].lx = tree[root << 1].lx;
	tree[root].rx = tree[root << 1 | 1].rx;
	tree[root].cnt = tree[root << 1].cnt + tree[root << 1 | 1].cnt;
	if (tree[root << 1].rx == tree[root << 1 | 1].lx) tree[root].cnt--;
}

void push_down(int root)
{
	int mark = tree[root].mark;
	if (mark != -1) {
		tree[root << 1].mark = tree[root << 1 | 1].mark = mark;
		tree[root << 1].cnt = tree[root << 1 | 1].cnt = 1;
		tree[root << 1].lx = tree[root << 1].rx = mark;
		tree[root << 1 | 1].lx = tree[root << 1 | 1].rx = mark;
		tree[root].mark = -1;
	}
}

void build(int left, int right, int root)
{
	tree[root].l = left;
	tree[root].r = right;
	tree[root].mark = -1;
	int mid = (left + right) >> 1;
	if (left == right) {
		tree[root].lx = tree[root].rx = a[id[mid]];
		tree[root].cnt = 1;
		return;
	}
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	push_up(root);
}

void modify(int left, int right, int color, int root)
{
	if (left <= tree[root].l && tree[root].r <= right) {
		tree[root].mark = tree[root].lx = tree[root].rx = color;
		tree[root].cnt = 1;
		return;
	}
	push_down(root);
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (left <= mid) modify(left, right, color, root << 1);
	if (right >= mid + 1) modify(left, right, color, root << 1 | 1);
	push_up(root);
}

int query(int left, int right, int root)
{
	if (left <= tree[root].l && tree[root].r <= right) return tree[root].cnt;
	push_down(root);
	int mid = (tree[root].l + tree[root].r) >> 1;
	int ans = 0;
	if (left <= mid) ans += query(left, right, root << 1);
	if (right >= mid + 1) ans += query(left, right, root << 1 | 1);
	if (left <= mid && right >= mid + 1 && tree[root << 1].rx == tree[root << 1 | 1].lx) ans--;
	return ans;
}

int find_color(int pos, int root)
{
	if (tree[root].l == tree[root].r) return tree[root].lx;
	push_down(root);
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (pos <= mid) return find_color(pos, root << 1);
	if (pos >= mid + 1) return find_color(pos, root << 1 | 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs_1(1, 0, 0);
	dfs_2(1, 1);
	build(1, n, 1);
	char mes[2];
	while (m--) {
		scanf("%s", mes);
		if (mes[0] == 'C') {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			while (top[u] != top[v]) {
				if (deep[top[u]] < deep[top[v]]) swap(u, v);
				modify(in[top[u]], in[u], c, 1);
				u = fa[top[u]];
			}
			if (deep[u] < deep[v]) swap(u, v);
			modify(in[v], in[u], c, 1);
		}
		if (mes[0] == 'Q') {
			int u, v;
			scanf("%d %d", &u, &v);
			int ans = 0;
			while (top[u] != top[v]) {
				if (deep[top[u]] < deep[top[v]]) swap(u, v);
				ans += query(in[top[u]], in[u], 1);
				if (find_color(in[top[u]], 1) == find_color(in[fa[top[u]]], 1)) ans--;
				u = fa[top[u]];
			}
			if (deep[u] < deep[v]) swap(u, v);
			ans += query(in[v], in[u], 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}
