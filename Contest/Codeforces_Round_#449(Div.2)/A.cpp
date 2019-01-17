//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: Shili_Xu@qq.com 
// Created Time: 2017年12月23日 星期六 21时14分40秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;

int n, m;
char str[MAXN];

int main()
{
	scanf("%d %d", &m, &m);
	scanf("%s", str);
	int l, r;
	char x[2], y[2];
	while (m--) {
		scanf("%d %d %s %s", &l, &r, x, y);
		for (int i = l - 1; i <= r - 1; i++)
			if (str[i] == x[0]) str[i] = y[0];
	}
	printf("%s\n", str);
	return 0;
}
