//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月29日 星期四 21时26分22秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int a[MAXN];

bool ok(int i)
{
	return (1 <= i && i <= n);
}

long long min(long long a, long long b)
{
	return (a < b ? a : b);
}

int main()
{
	scanf("%d", &n);
	int mx = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (mx < a[i]) {
			mx = a[i];
			cnt = 0;
		}
		if (mx == a[i]) cnt++;
	}
	if (mx == 0) {
		printf("0\n");
		return 0;
	}
	if (cnt > 1) {
		bool flag = false, tag = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] == mx) {
				if (ok(i - 1) && (a[i - 1] == mx || a[i - 1] >= 1)) flag = true;
				if (ok(i + 1) && (a[i + 1] == mx || a[i + 1] >= 1)) flag = true;
				if (ok(i - 1) && a[i - 1] <= mx - 2) tag = true;
				if (ok(i + 1) && a[i + 1] <= mx - 2) tag = true;
			}
		}
		long long ans = (long long)cnt * mx;
		if (flag) ans = min(ans, (long long)mx + 1);
		if (tag) ans = min(ans, (long long)(cnt - 1) * mx);
		printf("%lld\n", ans);
	}
	else {
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (a[i] == mx) {
				if (ok(i - 1) && a[i - 1] < mx - 2) flag = true;
				if (ok(i + 1) && a[i + 1] < mx - 2) flag = true;
			}
		}
		int cc = 0;
		for (int i = 1; i <= n; i++) if (a[i] == mx - 1) cc++;
		long long ans = mx;
		if (flag) ans = min(ans, (long long)(cc + 1) * (mx - 1));
		printf("%lld\n", ans);
	}
	return 0;
}
