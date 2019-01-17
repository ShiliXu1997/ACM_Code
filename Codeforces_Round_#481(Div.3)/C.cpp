//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 17时51分47秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, m;
ll sum[MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		sum[i] = sum[i - 1] + x;
	}
	for (int i = 1; i <= m; i++) {
		ll x;
		scanf("%lld", &x);
		int pos = (int)(upper_bound(sum + 1, sum + 1 + n, x) - sum);
		ll room = x - (sum[pos - 1] - 1);
		printf("%d %lld\n", pos, room);
	}
	return 0;
}
