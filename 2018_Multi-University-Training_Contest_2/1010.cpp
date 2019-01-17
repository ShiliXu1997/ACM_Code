//******************************************************************************
// File Name: 1010.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月25日 星期三 12时58分51秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, x, y;
int a[MAXN], b[MAXN], c[MAXN];

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, int num)
{
	while (x <= n) {
		c[x] += num;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while (x) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	while (scanf("%d %d %d", &n, &x, &y) == 3) {
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		memset(c, 0, sizeof(c));
		ll all_x = 0;
		for (int i = 1; i <= n; i++) {
			int index = (int)(lower_bound(b + 1, b + 1 + n, a[i]) - b);
			modify(index, 1);
			all_x += sum(n) - sum(index);
		}
		if (x <= y) {
			printf("%lld\n", all_x * x);
			continue;
		}
		printf("%lld\n", all_x * y);
	}
	return 0;
}
