//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月11日 星期日 12时41分54秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int n;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int sum1 = 0, sum2 = 0;
	for (int i = n; i >= 1; i -= 2) sum1 += a[i];
	for (int i = n - 1; i >= 1; i -= 2) sum2 += a[i];
	printf("%d %d\n", sum1, sum2);
	return 0;
}
