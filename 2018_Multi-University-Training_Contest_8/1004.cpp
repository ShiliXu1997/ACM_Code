//******************************************************************************
// File Name: 1004.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月15日 星期三 15时16分22秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 205;

int t, h, w;
int grid[MAXN][MAXN];

bool odd(int x)
{
	return (x & 1);
}

void print()
{
	for (int i = 1; i <= h; i++, puts(""))
		for (int j = 1; j <= w; j++) printf("%c", !grid[i][j] ? '(' : ')');
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &w);
		if ((odd(h) && !odd(w)) || (!odd(h) && odd(w))) {
			if (!odd(h)) {
				for (int i = 1; i <= w; i++)
					for (int j = 1, now = 0; j <= h; j++, now ^= 1) grid[j][i] = now;
			}
			else {
				for (int i = 1; i <= h; i++)
					for (int j = 1, now = 0; j <= w; j++, now ^= 1) grid[i][j] = now;
			}
		}
		else
		if (!odd(h) && !odd(w)) {
			if (h >= 6 && w >= 6) {
				for (int i = 1; i <= h; i++) grid[i][1] = 0, grid[i][w] = 1;
				for (int i = 1; i <= w; i++) grid[1][i] = 0, grid[h][i] = 1;
				for (int i = 2; i <= h - 1; i++)
					for (int j = 2, now = ((i & 1) == (j & 1)); j <= w - 1; j++, now ^= 1) grid[i][j] = now;
			}
			else
			if (h == 2) {
				for (int i = 1; i <= w; i++) grid[1][i] = 0, grid[2][i] = 1;
			}
			else
			if (w == 2) {
				for (int i = 1; i <= h; i++) grid[i][1] = 0, grid[i][2] = 1;
			}
			else
			if (h == 4) {
				for (int i = 1; i <= w; i++) grid[1][i] = 0, grid[h][i] = 1;
				for (int i = 1, now = 0; i <= w; i++, now ^= 1) grid[2][i] = now, grid[3][i] = now ^ 1;
			}
			else
			if (w == 4) {
				for (int i = 1; i <= h; i++) grid[i][1] = 0, grid[i][w] = 1;
				for (int i = 1, now = 0; i <= h; i++, now ^= 1) grid[i][2] = now, grid[i][3] = now ^ 1;
			}
		}
		else
			memset(grid, 0, sizeof(grid));
		print();
	}
	return 0;
}
