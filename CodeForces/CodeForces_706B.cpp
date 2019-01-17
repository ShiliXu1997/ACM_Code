//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月21日 星期三 21时06分46秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	scanf("%d", &q);
	while (q--) {
		int x, ans = 0;
		scanf("%d", &x);
		ans += (int)(upper_bound(a + 1, a + 1 + n, x) - a) - 1;
		printf("%d\n", ans);
	}
	return 0;
}
