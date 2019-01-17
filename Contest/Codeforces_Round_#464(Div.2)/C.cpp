//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月02日 星期一 22时14分51秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, s, f;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
	scanf("%d %d", &s, &f);
	int ans = 0, index;
	for (int i = 1; i <= n; i++) {
		int cnt, l = (s - i + n) % n + 1, r = (f - 1 - i + n) % n + 1;
		if (l > r)
			cnt = a[n] - a[l - 1] + a[r];
		else
			cnt = a[r] - a[l - 1];
		if (cnt > ans) {
			ans = cnt;
			index = i;
		}
	}
	printf("%d", index);
	return 0;
}
