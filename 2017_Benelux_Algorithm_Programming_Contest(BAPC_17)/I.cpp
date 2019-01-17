//************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月11日 星期日 21时15分13秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105, INF = 0x3f3f3f3f;

int x, y, flag;
int dp[MAXN][MAXN][2];
bool visited[MAXN][MAXN][2];

int dfs(int x, int y, int p)
{
	if (x == 0 || y == 0) return 0;
	if (visited[x][y][p]) return dp[x][y][p];
	visited[x][y][p] = true;
	dp[x][y][p] = -INF;
	if (!p) {
		for (int i = 0; i <= y - 1; i++) {
			int ans = -dfs(x, i, 1);
			if (((y - i) * x) & 1) {
				if ((flag & 1) == (y & 1))
					ans += 1;
				else
					ans -= 1;
			}
			dp[x][y][p] = max(dp[x][y][p], ans);
		}
	}
	else {
		for (int i = 0; i <= x - 1; i++) {
			int ans = -dfs(i, y, 0);
			if (((x - i) * y) & 1) {
				if ((flag & 1) == (x & 1))
					ans += 1;
				else
					ans -= 1;
			}
			dp[x][y][p] = max(dp[x][y][p], ans);
		}
	}
	return dp[x][y][p];
}

int main()
{
	scanf("%d %d", &x, &y);
	flag = y;
	memset(visited, false, sizeof(visited));
	printf("%d", dfs(x, y, 0));
	return 0;
}
