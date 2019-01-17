//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月25日 星期日 14时53分23秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, m, x, y;
bool flag;
vector<int> connect[MAXN];
int good[MAXN], bad[MAXN], visited[MAXN];

void dfs(int u, int gb)
{
	if (!flag) return;
	for (int i = 0; i < connect[u].size(); i++) {
		int v = connect[u][i];
		if (visited[v] == gb) {
			flag = false;
			return;
		}
		if (visited[v] == 0) {
			int now = -gb;
			visited[v] = now;
			if (now == 1) good[++x] = v;
			if (now == -1) bad[++y] = v;
			dfs(v, -gb);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &n, &m, &x, &y) == 4) {
		for (int i = 1; i <= n; i++) connect[i].clear();
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			connect[a].push_back(b);
			connect[b].push_back(a);
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= x; i++) scanf("%d", &good[i]), visited[good[i]] = 1;
		for (int i = 1; i <= y; i++) scanf("%d", &bad[i]), visited[bad[i]] = -1;
		flag = true;
		for (int i = 1; i <= x && flag; i++) dfs(good[i], 1);
		for (int i = 1; i <= y && flag; i++) dfs(bad[i], -1);
		for (int i = 1; i <= n && flag; i++)
			if (visited[i] == 0 && connect[i].size() > 0) {
				visited[i] = 1;
				good[++x] = i;
				dfs(i, 1);
			}
		if (x + y != n) flag = false;
		if (flag) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

