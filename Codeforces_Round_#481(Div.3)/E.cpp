//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 17时19分46秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int n, w;

int main()
{
	scanf("%d %d", &n, &w);
	int sum = 0, mn = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		mn = min(mn, sum);
		mx = max(mx, sum);
	}
	int ans = (w - mx) + mn + 1;
	printf("%d\n", ans >= 0 ? ans : 0);
	return 0;
}
