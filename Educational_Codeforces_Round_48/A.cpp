//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月03日 星期五 22时28分10秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n;
ll m;
ll a[MAXN];

int main()
{
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	ll now = m;
	for (int i = 1; i <= n; i++) {
		ll pages = 0;
		if (now >= a[i]) {
			now -= a[i];
			if (now == 0) {
				pages++;
				now = m;
			}
		}
		else {
			a[i] -= now;
			pages += 1 + a[i] / m;
			now = m - a[i] % m;
		}
		printf("%lld ", pages);
	}
	return 0;
}
