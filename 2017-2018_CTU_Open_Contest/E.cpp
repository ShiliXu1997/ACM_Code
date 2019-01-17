//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月10日 星期六 15时06分48秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int m, n, h, x, y;
int g[MAXN][MAXN];

bool ok(int x, int y)
{
	return (1 <= x && x <= m && 1 <= y && y <= m);
}

int main()
{
	while (scanf("%d %d", &m, &n) == 2) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i <= m + 1; i++) g[0][i] = g[m + 1][i] = g[i][0] = g[i][m + 1] = 6;
		while (n--) {
			scanf("%d %d %d", &h, &x, &y);
			int rtx = m - y, rty = x + 1;
			if (ok(rtx, rty + 1)) g[rtx][rty + 1] = 2;
			if (ok(rtx, rty - 1)) g[rtx][rty - 1] = 2;
			if (h == 0) {
				if (ok(rtx, rty)) g[rtx][rty] = 1;
				continue;
			}
			for (int i = rtx; i >= rtx - h; i--) if (ok(i, rty)) g[i][rty] = 3;
			for (int i = rtx - 1; i >= rtx - h; i--) if (ok(i, rty - 1)) g[i][rty - 1] = 4;
			for (int i = rtx - 1; i >= rtx - h; i--) if (ok(i, rty + 1)) g[i][rty + 1] = 5;
			if (ok(rtx - h - 1, rty)) g[rtx - h - 1][rty] = 7;
		}
		for (int i = 0; i <= m + 1; i++)
			for (int j = 0; j <= m + 1; j++) {
				if (g[i][j] == 0) printf(".");
				if (g[i][j] == 1) printf("o");
				if (g[i][j] == 2) printf("_");
				if (g[i][j] == 3) printf("|");
				if (g[i][j] == 4) printf("/");
				if (g[i][j] == 5) printf("\\");
				if (g[i][j] == 6) printf("*");
				if (g[i][j] == 7) printf("^");
				if (j == m + 1) printf("\n");
			}
		printf("\n");
	}
	return 0;
}
