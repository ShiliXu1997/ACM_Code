//******************************************************************************
// File Name: L.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月30日 星期一 13时17分26秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 90;

int t, a, b, c;
char g[MAXN][MAXN];


int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &c);
		int row = 2 * b + 2 * c + 1, col = 2 * a + 2 * b + 1;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) g[i][j] = '.';
		for (int r = row, t = 1; t <= c; r -= 2, t++) {
			for (int i = 1; i <= 2 * a - 1; i += 2) {
				g[r][i] = '+';
				g[r][i + 1] = '-';
				g[r - 1][i] = '|';
				if (i == 2 * a - 1) {
					g[r][i + 2] = '+';
					g[r - 1][i + 2] = '|';
				}
			}
		}
		for (int r = 1, t = 1; t <= b; r += 2, t++) {
			for (int i = col - (t - 1) * 2; i >= col - (t - 1) * 2 - 2 * a + 2; i -= 2) {
				g[r][i] = '+';
				g[r][i - 1] = '-';
				g[r + 1][i - 1] = '/';
				if (i == col - (t - 1) * 2 - 2 * a + 2) {
					g[r][i - 2] = '+';
					g[r + 1][i - 3] = '/';
				}
			}
			if (t == b) {
				for (int i = col - (t - 1) * 2 - 2; i >= col - (t - 1) * 2 - 2 * a - 1; i -= 2) {
					g[r + 2][i] = '+';
					g[r + 2][i - 1] = '-';
				}
				g[r + 2][col - (t - 1) * 2 - 2 * a + 1 - 3] = '+';
			}
		}
		for (int i = col, t = 1; t <= b; i -= 2, t++) {
			for (int r = 2 + (t - 1) * 2; r <= 2 * c + (t - 1) * 2; r += 2) {
				g[r][i] = '|';
				g[r + 1][i] = '+';
				g[r + 2][i - 1] = '/';
			}
		}
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) printf("%c", g[i][j]);
			printf("\n");
		}
	}
	return 0;
}
