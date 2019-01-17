//************************************************************************
// File Name: L.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月29日 星期四 18时44分55秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;

int n;
int ans[MAXN];

int main()
{
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ans[x] = i;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}
