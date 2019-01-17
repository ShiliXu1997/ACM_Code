//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月27日 星期五 14时02分02秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, k;
int a[MAXN];

int gcd(int a, int b)
{
	return (!b ? a : gcd(b, a % b));
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int now = k;
	for (int i = 1; i <= n; i++) now = gcd(now, a[i]);
	printf("%d\n", k / now);
	for (int i = 0; i < k; i += now) printf("%d ", i);
	return 0;
}
