//******************************************************************************
// File Name: 1005.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月15日 星期三 12时14分19秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 5;

int t, n;
char s[MAXN];
int grid[MAXN][MAXN];

void rotate(int x, int y, char p)
{
	int tmp = grid[x][y];
	if (p == 'C') {
		grid[x][y] = grid[x + 1][y];
		grid[x + 1][y] = grid[x + 1][y + 1];
		grid[x + 1][y + 1] = grid[x][y + 1];
		grid[x][y + 1] = tmp;
	}
	else {
		grid[x][y] = grid[x][y + 1];
		grid[x][y + 1] = grid[x + 1][y + 1];
		grid[x + 1][y + 1] = grid[x + 1][y];
		grid[x + 1][y] = tmp;
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= 3; i++) {
			scanf("%s", s);
			for (int j = 1; j <= 3; j++)
				grid[i][j] = s[j - 1] - '0';
		}
		while (n--) {
			scanf("%s", s);
			int x, y;
			if (s[0] == '1') x = 1, y = 1;
			if (s[0] == '2') x = 1, y = 2;
			if (s[0] == '3') x = 2, y = 1;
			if (s[0] == '4') x = 2, y = 2;
			rotate(x, y, s[1]);
		}
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) printf("%d", grid[i][j]);
			puts("");
		}
	}
	return 0;
}
