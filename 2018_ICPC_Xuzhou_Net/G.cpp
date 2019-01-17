//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月09日 星期日 13时23分42秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 50005;

int n;
int x[MAXN], y[MAXN], nowx[MAXN], nowy[MAXN];
set<int> stx, sty;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &x[i], &y[i]);
	ll ans = 0;
	set<int>::iterator it;
	stx.insert(0); sty.insert(0);
	for (int i = n; i >= 1; i--) {
		ans += x[i] + y[i];
		it = stx.lower_bound(-x[i]);
		ans += *it;
		it = sty.lower_bound(-y[i]);
		ans += *it;
		stx.insert(-x[i]);
		sty.insert(-y[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
