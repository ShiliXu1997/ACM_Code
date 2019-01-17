//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月30日 星期一 13时00分26秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, n, p, q;
vector<int> g[MAXN];
int a[MAXN];

void init()
{
	for (int i = 1; i <= n; i++) g[i].clear();
}

void add_edge(int from, int to)
{
	g[from].push_back(to);
}

void dfs(int rt, int f, int d)
{
	if (!d)
		p ^= a[rt];
	else
		q ^= a[rt];
	for (int i = 0; i < g[rt].size(); i++) {
		if (g[rt][i] == f) continue;
		dfs(g[rt][i], rt, d ^ 1);
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		p = q = 0;
		dfs(1, 0, 0);
		if (p == q)
			printf("D\n");
		else
			printf("Q\n");
	}
	return 0;
}
