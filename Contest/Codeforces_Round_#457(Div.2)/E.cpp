//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月04日 星期日 19时35分40秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct edge {
	int to, next;
};

int n, q, cnt, root, tot;
int in[MAXN], out[MAXN], mp[MAXN],head[MAXN], deep[MAXN];
int up[MAXN][18];
long long value[MAXN], c[MAXN], d[MAXN];
edge e[2 * MAXN];

int lowbit(int x)
{
	return (x & -x);
}

void modify(long long array[], int x, long long num)
{
	while (x <= n) {
		array[x] += num;
		x += lowbit(x);
	}
}

long long sum(long long array[], int x)
{
	long long ans = 0;
	while (x) {
		ans += array[x];
		x -= lowbit(x);
	}
	return ans;
}

void addedge(int a, int b)
{
	tot++;
	e[tot].to = b;
	e[tot].next = head[a];
	head[a] = tot;
}

void dfs(int u, int fa, int depth)
{
	cnt++;
	in[u] = cnt;
	mp[cnt] = u;
	deep[u] = depth;
	up[u][0] = fa;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (v != fa) dfs(v, u, depth + 1);
	}
	out[u] = cnt;
}

void init()
{
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= n; j++)
			up[j][i] = up[up[j][i - 1]][i - 1];
}

int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	int diff = deep[u] - deep[v];
	for (int i = 17; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main()
{
	root = 1; tot = 0;
	memset(head, 0, sizeof(head));
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &value[i]);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	cnt = 0;
	dfs(root, 0, 1);
	modify(c, 1, value[1]);
	d[1] = 0;
	for (int i = 2; i <= n; i++) {	
		modify(c, i, value[mp[i]] - value[mp[i - 1]]);
		modify(d, i, (value[mp[i]] - value[mp[i - 1]]) * (i - 1));
	}
	init();
	for (int i = 1; i <= q; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1)
			scanf("%d", &root);
		if (op == 2) {
			int u, v, p;
			long long x;
			scanf("%d %d %lld", &u, &v, &x);
			if (in[root] <= in[u] && in[u] <= out[root] && in[root] <= in[v] && in[v] <= out[root]) 
				p = lca(u, v);
			else
			if ((in[root] <= in[u] && in[u] <= out[root]) || (in[root] <= in[v] && in[v] <= out[root]))
				p = root;
			else {
				int p1 = lca(u, v), p2 = lca(u, root), p3 = lca(v, root);
				p = (deep[p1] > deep[p2] ? p1 : p2);
				p = (deep[p] > deep[p3] ? p : p3);
			}
			if (root == p ) {
				modify(c, in[1], x);
				modify(c, out[1] + 1, -x);
				modify(d, in[1], x * (in[1] - 1));
				modify(d, out[1] + 1, -x * out[1]);
			}
			else
			if (in[p] <= in[root] && in[root] <= out[p]) {
				int diff = deep[root] - deep[p] - 1, hr = root;
				for (int i = 17; i >= 0; i--)
					if (diff & (1 << i)) hr = up[hr][i];
				modify(c, in[1], x);
				modify(c, out[1] + 1, -x);
				modify(d, in[1], x * (in[1] - 1));
				modify(d, out[1] + 1, -x * out[1]);
				modify(c, in[hr], -x);
				modify(c, out[hr] + 1, x);
				modify(d, in[hr], -x * (in[hr] - 1));
				modify(d, out[hr] + 1, x * out[hr]);
			}
			else {
				modify(c, in[p], x);
				modify(c, out[p] + 1, -x);
				modify(d, in[p], x * (in[p] - 1));
				modify(d, out[p] + 1, -x * out[p]);
			}	
		}
		if (op == 3) {
			int p;
			scanf("%d", &p);
			long long ans;
			if (root == p )
				ans = sum(c, n) * n - sum(d, n);
			else
			if (in[p] <= in[root] && in[root] <= out[p]) {
				int diff = deep[root] - deep[p] - 1, hr = root;
				for (int i = 17; i >= 0; i--)
					if (diff & (1 << i)) hr = up[hr][i];
				ans = sum(c, n) * n - sum(d, n);
				ans -= ((sum(c, out[hr]) * out[hr] - sum(d, out[hr])) - (sum(c, in[hr] - 1) * (in[hr] - 1) - sum(d, in[hr] - 1)));
			}
			else
				ans = (sum(c, out[p]) * out[p] - sum(d, out[p])) - (sum(c, in[p] - 1) * (in[p] - 1) - sum(d, in[p] - 1));
			printf("%lld\n", ans);
		}
	}
	return 0;
}
