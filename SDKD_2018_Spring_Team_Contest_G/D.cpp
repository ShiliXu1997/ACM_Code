//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 16时15分50秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50;

int a[MAXN];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) a[i + j]++;
	int mx = 0;
	for (int i = 1; i <= n + m; i++) mx = max(mx, a[i]);
	for (int i = 1; i <= n + m; i++)
		if (mx == a[i]) printf("%d\n", i);
	return 0;
}
