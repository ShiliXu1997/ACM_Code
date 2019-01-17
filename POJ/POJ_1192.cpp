//******************************************************************************
// File Name: POJ_1192.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月07日 星期二 17时06分43秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

struct node {
	int x, y, c;
};

int n;
node p[MAXN];
vector<int> g[MAXN];
int dp[MAXN][2];

void dfs(int u, int fa)
{
	dp[u][0] = 0;
	dp[u][1] = p[u].c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		dp[u][0] = max(dp[u][0], max(dp[v][0], dp[v][1]));
		dp[u][1] += (dp[v][1] > 0 ? dp[v][1] : 0);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].c);
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++) {
			if (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) == 1)
				g[i].push_back(j), g[j].push_back(i);
		}
	dfs(1, 0);
	printf("%d\n", max(dp[1][0], dp[1][1]));
	return 0;
}
