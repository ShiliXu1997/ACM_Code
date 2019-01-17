//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年01月26日 星期五 16时23分58秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

long long n;
int k;
deque<int> q;

int main()
{
	scanf("%lld %d", &n, &k);
	for (int i = 0; i <= 60; i++)
		if (n & ((long long)1 << i)) q.push_back(i);	
	if (q.size() > k) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	while (true) {
		int mx = q.back(), cnt = 0, diff = k - q.size();
		while (!q.empty() && q.back() == mx) {
			q.pop_back();
			cnt++;
		}
		if (cnt <= diff)
			for (int i = 1; i <= 2 * cnt; i++) q.push_back(mx - 1);
		else {
			for (int i = 1; i <= cnt; i++) q.push_back(mx);
			break;
		}
	}
	int mn = q.front(); q.pop_front();
	int diff = k - q.size() - 1;
	for (int i = 1; i <= diff; i++) q.push_front(--mn);
	q.push_front(mn);
	for (deque<int>::iterator it = q.end() - 1; it >= q.begin(); --it) printf("%d ", *it);
	return 0;
}

