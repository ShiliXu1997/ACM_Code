//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月07日 星期五 00时14分26秒
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

int n;
priority_queue<ll> a, b;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		a.push(x);
	}
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		b.push(x);
	}
	ll cnt_a = 0, cnt_b = 0, p, q;
	for (int i = 1; i <= n; i++) {
		if (!a.empty() && !b.empty()) {
			p = a.top();
			q = b.top();
			if (p > q)
				cnt_a += p, a.pop();
			else
				b.pop();
		}
		else {
			if (a.empty())
				b.pop();
			else {
				p = a.top();
				cnt_a += p, a.pop();
			}
		}
		if (!a.empty() && !b.empty()) {
			p = a.top();
			q = b.top();
			if (p < q)
				cnt_b += q, b.pop();
			else
				a.pop();
		}
		else {
			if (b.empty())
				a.pop();
			else {
				q = b.top();
				cnt_b += q, b.pop();
			}
		}
	}
	printf("%lld\n", cnt_a - cnt_b);
	return 0;
}
