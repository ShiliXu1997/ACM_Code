//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 23时59分59秒
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

int n;

int main()
{
	scanf("%d", &n);
	if (n <= 2)
		printf("No\n");
	else {
		printf("Yes\n");
		int a = n / 2, b = n - a;
		printf("%d ", a);
		for (int i = 2; i <= n; i += 2) printf("%d ", i);
		puts("");
		printf("%d ", b);
		for (int i = 1; i <= n; i += 2) printf("%d ", i);
	}
	return 0;
}
