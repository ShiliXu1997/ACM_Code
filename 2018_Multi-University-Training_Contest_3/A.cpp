//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月31日 星期二 13时22分41秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e7 + 5;

struct deque {
	int head, tail;
	int q[MAXN];

	void init()
	{
		head = tail = 0;
	}

	bool empty()
	{
		return head == tail;
	}

	int size()
	{
		return tail - head;
	}

	int front()
	{
		return q[head];
	}

	int back()
	{
		return q[tail - 1];
	}

	void pop_front()
	{
		head++;
	}

	void push_back(int x)
	{
		q[tail++] = x;
	}

	void pop_back()
	{
		tail--;
	}
};

int t, n, m, k, p, q, r, mod;
int a[MAXN];
deque que;

int main()
{
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d %d %d %d", &n, &m, &k, &p, &q, &r, &mod);
		for (int i = 1; i <= n; i++) {
			if (i <= k)
				scanf("%d", &a[i]);
			else
				a[i] = ((ll)p * a[i - 1] + (ll)q * i + (ll)r) % mod;
		}
		que.init();
		ll A = 0, B = 0;
		for (int i = n; i >= 1; i--) {
			while (!que.empty() && a[i] >= a[que.back()]) que.pop_back();
			que.push_back(i);
			if (!que.empty() && que.front() >= i + m) que.pop_front();
			if (i <= n - m + 1) {
				A += (ll)a[que.front()] ^ (ll)i;
				B += (ll)que.size() ^ (ll)i;
			}
		}
		printf("%lld %lld\n", A, B);
	}
	return 0;
}

