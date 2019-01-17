//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 22时53分58秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, s;
int a[MAXN];

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int mid = (n + 1) >> 1, cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < s) cnt_1++;
		if (a[i] == s) cnt_2++;
		if (a[i] > s) cnt_3++;
	}
	ll ans;
	if (cnt_1 + 1 <= mid && mid <= cnt_1 + cnt_2)
		ans = 0;
	else {
		ans = 0;
		if (cnt_1 >= mid) {
			for (int i = mid; i <= cnt_1; i++) ans += (ll)(s - a[i]);
		}
		else {
			for (int i = cnt_1 + cnt_2 + 1; i <= mid; i++) ans += (ll)(a[i] - s);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
