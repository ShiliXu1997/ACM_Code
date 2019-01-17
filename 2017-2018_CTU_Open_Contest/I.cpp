//************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月10日 星期六 16时39分12秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1e5 + 5;

int n, xxcnt, yycnt;
int xxnum[MAXN], yynum[MAXN];
map<int, int> xx, yy;

int main()
{
	while (scanf("%d", &n) == 1) {
		xxcnt = yycnt = 0;
		xx.clear(); yy.clear();
		for (int p = 1; p <= n; p++) {
			int x, y;
			scanf("%d %d", &x, &y);
			int i = x + y, j = y - x;
			if (!xx.count(i)) xx[i] = 0, xxnum[++xxcnt] = i;
			if (!yy.count(j)) yy[j] = 0, yynum[++yycnt] = j;
			xx[i]++; yy[j]++;
		}
		long long ans = 0;
		for (int i = 1; i <= xxcnt; i++)
			if (xx[xxnum[i]] > 1) ans += (long long)xx[xxnum[i]] * (xx[xxnum[i]] - 1);
		for (int i = 1; i <= yycnt; i++)
			if (yy[yynum[i]] > 1) ans += (long long)yy[yynum[i]] * (yy[yynum[i]] - 1);
		double d = (double)ans / ((double)n * n);
		printf("%f\n", d);
	}
	return 0;
}
