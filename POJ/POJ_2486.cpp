//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月21日 星期三 20时57分07秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 205;

struct edge {
	int to, next;
};

int n, m, cnt;
int head[MAXN], num[MAXN];
int dp[MAXN][MAXN][2];
edge e[MAXN];

void add_edge(int a, int b)
{
	cnt++;
	e[cnt].to = b;
	e[cnt].next = head[a];
	head[a] = cnt;
}

void dfs(int u, int fa, int deep)
{
	int mx = m - deep;
	for (int i = 0; i <= mx; i++) dp[u][i][0] = dp[u][i][1] = num[u];
	if (mx == 0) return;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v, u, deep + 1);
		for (int j = mx; j >= 1; j--) {
			for (int k = 1; k <= j; k++) {
				if (k >= 2) dp[u][j][1] = max(dp[u][j][1], dp[u][j - k][1] + dp[v][k - 2][1]);
				dp[u][j][0] = max(dp[u][j][0], dp[u][j - k][1] + dp[v][k - 1][0]);
				dp[u][j][0] = max(dp[u][j][0], dp[u][j - k][1] + dp[v][k - 1][1]);
				dp[u][j][0] = max(dp[u][j][0], dp[u][j - k][0] + dp[v][k - 2][1]);
			}
		}
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		cnt = 0;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n - 1; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			add_edge(a, b);
			add_edge(b, a);
		}
		dfs(1, 0, 0);
		printf("%d\n", max(dp[1][m][0], dp[1][m][1]));
	}
	return 0;
}

