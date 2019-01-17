//******************************************************************************
// File Name: 1005.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月26日 星期四 20时14分32秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2500, P = 47;

int grid[MAXN][MAXN];

int main()
{
	memset(grid, 0, sizeof(grid));
	int n = 2000;
	printf("%d\n", n);
	for (int i = 1; i <= P; i++)
		for (int j = 1; j <= P; j++)
			for (int k = 1; k <= P; k++)
				grid[(i - 1) * P + j][(k - 1) * P + ((k - 1) * (j - 1) + i) % P] = 1;
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++)
			printf("%d", grid[j][k]);
		printf("\n");
	}
	return 0;
}
