//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月26日 星期日 13时49分50秒
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

int t, n;
priority_queue<int, vector<int>, greater<int> > q;
map<int, int> done;

int main()
{
	scanf("%d", &t);
	while (t--) {
		while (!q.empty()) q.pop();
		done.clear();
		scanf("%d", &n);
		int cnt = 0;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (q.empty() || q.top() >= x)
				q.push(x);
			else {
				int y = q.top(); q.pop();
				if (done.count(y) && done[y] > 0) done[y]--, cnt--;
				ans += (x - y);
				cnt++;
				q.push(x);
				q.push(x);
				done[x]++;
			}
		}
		printf("%lld %d\n", ans, cnt * 2);
	}
	return 0;
}
