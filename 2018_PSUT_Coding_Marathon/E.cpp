//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月28日 星期二 16时33分18秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 5005;

int n;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans++;
		int max_root = a[i], semax_root = 0, semax_son = 0, cnt_root = 1, cnt_son = 0, max_son = 0;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] > max_root) semax_root = max_root, max_root = a[j], semax_son = 0, cnt_root++, cnt_son = 0;
			if (semax_root < a[j] && a[j] < max_root && a[j] > semax_son) cnt_son++, semax_son = a[j];
			max_son = max(max_son, cnt_son);
			if (max_son)
				ans += cnt_root - 1 + max_son;
			else
				ans += cnt_root;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
