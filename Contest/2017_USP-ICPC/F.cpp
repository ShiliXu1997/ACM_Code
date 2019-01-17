//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 16时13分43秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, m, cnt;
int shi[MAXN], deep[MAXN], sum[MAXN][18];
vector<int> g[MAXN];

void add_edge(int from, int to)
{
	g[from].push_back(to);
}

void dfs_1(int u, int d)
{
	cnt = max(cnt, d);
	deep[u] = d;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs_1(v, d + 1);
	}
}

void dfs_2(int u, int d)
{
	sum[u][d] = shi[u];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs_2(v, d + 1);
		for (int j = d + 1; j <= cnt; j++) sum[u][j] += sum[v][j];
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &shi[1]);
	for (int i = 1; i <= n - 1; i++) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		add_edge(v, u);
		shi[u] = x;
	}
	cnt = 0;
	memset(sum, 0, sizeof(sum));
	dfs_1(1, 0);
	dfs_2(1, 0);
	while (m--) {
		int x;
		scanf("%d", &x);
		int ans = 0;
		for (int i = 0; i <= cnt; i++) {
			if (i < deep[x])
				ans = max(ans, sum[1][i]);
			else
				ans = max(ans, sum[1][i] - sum[x][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
