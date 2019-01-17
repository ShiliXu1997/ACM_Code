//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 11时53分33秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n, r, c;
int g[MAXN][MAXN];

int main()
{
	freopen("class.in", "r", stdin);
	freopen("class.out", "w", stdout);
	scanf("%d %d %d", &n, &r, &c);
	int ans = min(min(r, c), (n + 1) / 2), cnt = n;
	memset(g, 0, sizeof(g));
	for (int i = 1; i <= ans && i <= r; i++) g[i][1] = 1, cnt--;
	for (int j = 2; j <= ans && j <= c; j++) g[1][j] = 1, cnt--;
	for (int i = 1; i <= r && cnt; i++)
		for (int j = 1; j <= c && cnt; j++)
			if (!g[i][j]) g[i][j] = 1, cnt--;
	printf("%d\n", ans);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) printf("%c", (g[i][j] ? '#' : '.'));
		printf("\n");
	}
	return 0;
}
