//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 00时46分13秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n == 2 || n == 3 || n == 4 || n == 5)
		printf("-1\n");
	else {
		if (n & 1) {
			for (int i = 2; i <= n / 2 + 1; i++) printf("%d %d\n", 1, i);
			for (int i = n / 2 + 2; i <= n; i++) printf("%d %d\n", 2, i);
		}
		else {
			for (int i = 1; i <= n - 3; i++) printf("%d %d\n", i, i + 1);
			printf("%d %d\n%d %d\n", 2, n - 1, n - 3, n);
		}
	}
	for (int i = 1; i <= n - 1; i++) printf("%d %d\n", i, i + 1);
	return 0;
}
