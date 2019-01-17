//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月04日 星期六 00时30分32秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200;

int n, m;
int a[MAXN], b[MAXN];
int ans[MAXN][MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	int u = 0, v = 0;
	for (int i = 1; i < n; i++) u ^= a[i];
	for (int i = 1; i < m; i++) v ^= b[i];
	u ^= b[m];
	v ^= a[n];
	if (u != v)
		printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++) ans[i][j] = 0;
		for (int i = 1; i < n; i++) ans[i][m] = a[i];
		for (int i = 1; i < m; i++) ans[n][i] = b[i];
		ans[n][m] = u;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
			puts("");
		}
	}
	return 0;
}
