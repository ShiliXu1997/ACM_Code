//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月28日 星期二 00时36分22秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int n, m;
char grid[120][120];

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	char s[120];
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 1; j <= m; j++) grid[i][j] = s[j - 1];
	}
	bool flag = false;
	for (int i = 1; i <= n && !flag; i++)
		for (int j = 1; j <= m && !flag; j++)
			if (grid[i][j] == 'B') {
				int cnt = 0;
				for (int k = j; k <= m; k++) if (grid[i][k] == 'B') cnt++;
				cnt = cnt / 2 + 1;
				int x = i + cnt - 1, y = j + cnt - 1;
				printf("%d %d\n", x, y);
				flag = true;
			}
	return 0;
}
