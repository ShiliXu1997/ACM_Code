//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月31日 星期五 15时49分09秒
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

int n, k;
ll a[MAXN];
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	q.push(pair<ll, int>(a[1], 1));
	int cnt = 0;
	while (!q.empty()) {
		pair<ll, int> now = q.top(); q.pop();
		cnt++;
		if (cnt == k) {
			printf("%lld\n", now.first);
			break;
		}
		if (now.second < n) {
			q.push(pair<ll, int>(now.first - a[now.second] + a[now.second + 1], now.second + 1));
			q.push(pair<ll, int>(now.first + a[now.second + 1], now.second + 1));
		}
	}
	return 0;
}
