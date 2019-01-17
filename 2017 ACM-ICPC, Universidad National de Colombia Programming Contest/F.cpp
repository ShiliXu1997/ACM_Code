//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月21日 星期六 14时06分51秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;
ll a[MAXN], b[MAXN], c[MAXN];

int main()
{
	scanf("%d", &n);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		if (a[i] + b[i] <= c[i] || a[i] + c[i] <= b[i] || b[i] + c[i] <= a[i]) flag = false;
	}
	printf("%s", (flag ? "YES" : "NO"));
	return 0;
}
