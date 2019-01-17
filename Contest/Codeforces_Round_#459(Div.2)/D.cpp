//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月11日 星期日 11时10分10秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;

int n, m;
vector<pair<int, int> > connect[MAXN];
int dp[MAXN][MAXN][26];

bool solve(int x, int y, int mn)
{
	if (dp[x][y][mn] != -1) return dp[x][y][mn];
	dp[x][y][mn] = 0;
	for (int i = 0; i < connect[x].size(); i++) {
		int v = connect[x][i].first, ch = connect[x][i].second;
		if (ch >= mn && !solve(y, v, ch)) {
			dp[x][y][mn] = 1;
			break;
		}
	}
	return dp[x][y][mn];
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		char str[2];
		scanf("%d %d %s", &a, &b, str);
		connect[a].push_back(make_pair(b, str[0] - 'a'));
	}
	memset(dp, 0xff, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%c", (solve(i, j, 0) ? 'A' :'B'));
		printf("\n");
	}
	return 0;
}

