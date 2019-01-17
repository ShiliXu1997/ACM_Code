//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月03日 星期四 16时40分54秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 3005;

int t, n, m;
char g[MAXN][MAXN];

bool ok(int i, int j)
{
	return (0 <= i && i <= n + 1 && 0 <= j && j <= m + 1);
}

int main()
{
	scanf("%d", &t);
	char s[MAXN];
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n + 1; i++) g[i][0] = g[i][m + 1] = '.';
		for (int i = 0; i <= m + 1; i++) g[0][i] = g[n + 1][i] = '.';
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			for (int j = 1; j <= m; j++) g[i][j] = s[j - 1];
		}
		int cnt = 0;
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= m + 1; j++) {
				if (g[i][j] == '.') {
					int a = 0;
					if (ok(i - 1, j) && g[i - 1][j] == '#') a++;
					if (ok(i + 1, j) && g[i + 1][j] == '#') a++;
					if (ok(i, j - 1) && g[i][j - 1] == '#') a++;
					if (ok(i, j + 1) && g[i][j + 1] == '#') a++;
					if (a == 1) cnt++;
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}
