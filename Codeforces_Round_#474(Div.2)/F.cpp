//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月08日 星期日 02时15分25秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

struct edge {
	int from, to, dist;
	
	edge() {}
	edge(int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}

	bool operator<(const edge &another) const
	{
		return dist < another.dist;
	}
};

struct bit {
	int n;
	vector<int> a;

	bit(int _n = 0) : n(_n), a(_n * 2) {}

	void modify(int x, int num)
	{
		while (x <= n) {
			a[x] = max(a[x], num);
			x += x & -x;
		}
	}

	int get_max(int x)
	{
		int ans = 0;
		while (x) {
			ans = max(ans, a[x]);
			x -= x & -x;
		}
		return ans;
	}
};

int n, m;
vector<edge> e;
vector<edge> g[MAXN];
bit tree[MAXN];

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[to].push_back(edge(from, to, dist));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		add_edge(a, b, c);
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
		tree[i] = bit(g[i].size());
	}
	for (int i = 0; i < e.size(); i++) {
		int u = e[i].from, v = e[i].to;
		int pos = lower_bound(g[u].begin(), g[u].end(), e[i]) - g[u].begin();
		int relax = tree[u].get_max(pos) + 1;
		pos = lower_bound(g[v].begin(), g[v].end(), e[i]) - g[v].begin() + 1;
		tree[v].modify(pos, relax);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, tree[i].get_max(tree[i].n));
	printf("%d\n", ans);
	return 0;
}
