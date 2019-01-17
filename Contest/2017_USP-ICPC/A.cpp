//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 13时45分34秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, x;
int a[MAXN];

int main()
{
	scanf("%d %d", &n, &x);
	bool sm = true, bg = true, eq = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > x) bg = false;
		if (a[i] < x) sm = false;
		if (a[i] == x) eq = true;
	}
	if (eq)
		printf("1");
	else
	if (sm || bg)
		printf("-1");
	else
		printf("2");
	return 0;
}
