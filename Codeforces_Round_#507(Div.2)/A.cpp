//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 00时39分19秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 100;

int n, a, b;
int d[MAXN];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	int ans = 0;
	bool flag = true;
	for (int i = 1; i <= (n + 1) / 2 && flag; i++) {
		int j = n - i + 1;
		if (i == j) {
			if (d[i] == 2) ans += (a < b ? a : b);
			continue;
		}
		if (d[i] == d[j]) {
			if (d[i] == 2)
				ans += 2 * (a < b ? a : b);
			else
				continue;
		}
		if (d[i] != d[j] && d[i] != 2 && d[j] != 2) flag = false;
		if (d[i] == 0 || d[j] == 0) ans += a;
		if (d[i] == 1 || d[j] == 1) ans += b;
	}
	if (flag)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}
