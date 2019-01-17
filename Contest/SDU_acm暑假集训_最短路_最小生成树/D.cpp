//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月10日 星期六 22时47分39秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 505;

int n, m, cnt;
int ans[MAXN], in_degree[MAXN];
vector<int> connect[MAXN];
priority_queue<int, vector<int> > q;

void toposort()
{
	cnt = 0;
	memset(in_degree, 0, sizeof(in_degree));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < connect[i].size(); j++) in_degree[connect[i][j]]++;
	for (int i = 1; i <= n; i++) if (!in_degree[i]) q.push(-i);
	while (!q.empty()) {
		int u = -q.top(); q.pop();
		ans[++cnt] = u;
		for (int i = 0; i < connect[u].size(); i++) {
			int v = connect[u][i];
			in_degree[v]--;
			if (!in_degree[v]) q.push(-v);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) connect[i].clear();
		for (int i = 1; i <= m; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			connect[from].push_back(to);
		}
		toposort();
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], (i == n ? '\n' : ' '));
	}
	return 0;
}

