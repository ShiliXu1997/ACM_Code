//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 22时53分42秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, q;
ll a[MAXN], sum[MAXN];

int main()
{
	scanf("%d %d", &n, &q);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
	int index = 1;
	ll last = 0;
	for (int i = 1; i <= q; i++) {
		ll x;
		scanf("%lld", &x);
		x += sum[index - 1] + last;
		index = (int)(upper_bound(sum + index, sum + 1 + n, x)  - sum);
		if (index == n + 1)
			printf("%d\n", n), index = 1, last = 0;
		else
			printf("%d\n", (n - index + 1)), last = a[index] - (sum[index] - x);
	}
	return 0;
}
