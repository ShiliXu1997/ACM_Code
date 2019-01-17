//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月02日 星期一 22时52分00秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

int n;
int love[MAXN];

bool check(int i)
{
	return (love[love[love[i]]] == i);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &love[i]);
	bool flag = false;
	for (int i = 1; i <= n && !flag; i++) 
		if (check(i)) flag = true;
	printf("%s", (flag ? "YES" : "NO"));
	return 0;
}
