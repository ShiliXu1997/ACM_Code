//******************************************************************************
// File Name: Codeforces_867E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月26日 星期日 13时22分42秒
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

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (q.empty() || q.top() >= x)
			q.push(x);
		else {
			int now = q.top(); q.pop();
			ans += (x - now);
			q.push(x);
			q.push(x);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
