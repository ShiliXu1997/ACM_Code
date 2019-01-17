//******************************************************************************
// File Name: HDU_3966.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月15日 星期二 13时59分45秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 5e4 + 10;

struct edge {
	int to, next;
};

int n, m, p, tot, cnt;
edge e[MAXN << 1];
int fa[MAXN], top[MAXN], deep[MAXN], sz[MAXN], max_son[MAXN], in[MAXN], id[MAXN];
int a[MAXN], c[MAXN], head[MAXN];

void init()
{
	tot = cnt = 0;
	a[0] = sz[0] = id[0] = 0;
	memset(c, 0, sizeof(c));
	memset(head, 0, sizeof(head));
}

void add_edge(int from, int to)
{
	cnt++;
	e[cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;
}

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, int num)
{
	while (x <= n) c[x] += num, x += lowbit(x);
}

int sum(int x)
{
	int ans = 0;
	while (x) ans += c[x], x -= lowbit(x);
	return ans;
}

void dfs_1(int u, int f, int dpth)
{
	fa[u] = f;
	deep[u] = dpth;
	sz[u] = 1;
	max_son[u] = 0;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (v == f) continue;
		dfs_1(v, u, dpth + 1);
		if (sz[max_son[u]] < sz[v]) max_son[u] = v;
		sz[u] += sz[v];
	}
}

void dfs_2(int u, int tp)
{
	top[u] = tp;
	in[u] = ++tot;
	id[tot] = u;
	if (max_son[u]) dfs_2(max_son[u], tp);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (v == fa[u] || v == max_son[u]) continue;
		dfs_2(v, v);
	}
}

void change(int u, int v, int k)
{
	while (top[u] != top[v]) {
		if (deep[top[u]] < deep[top[v]]) swap(u, v);
		modify(in[top[u]], k);
		modify(in[u] + 1, -k);
		u = fa[top[u]];
	}
	if (deep[u] < deep[v]) swap(u, v);
	modify(in[v], k);
	modify(in[u] + 1, -k);
}

int main()
{
	while (scanf("%d %d %d", &n, &m, &p) == 3) {
		init();
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_1(1, 0, 0);
		dfs_2(1, 1);
		for (int i = 1; i <= n; i++) modify(i, a[id[i]] - a[id[i - 1]]);
		char mes[2];
		while (p--) {
			int u, v, k, who;
			scanf("%s", mes);
			if (mes[0] == 'I') {
				scanf("%d %d %d", &u, &v, &k);
				change(u, v, k);
			}
			if (mes[0] == 'D') {
				scanf("%d %d %d", &u, &v, &k);
				change(u, v, -k);
			}
			if (mes[0] == 'Q') {
				scanf("%d", &who);
				printf("%d\n", sum(in[who]));
			}
		}
	}
	return 0;
}
