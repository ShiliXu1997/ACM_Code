//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月14日 星期三 20时11分28秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 55;

int n, m;
long long a[MAXN], b[MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	int x;
	long long mx = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] * b[j] >= mx) {
				mx = a[i] * b[j];
				x = i;
			}
	mx = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		for (int j = 1; j <= m; j++) mx = (mx > a[i] * b[j] ? mx : a[i] * b[j]);
	}
	printf("%lld", mx);
	return 0;
}

