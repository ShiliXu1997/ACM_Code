//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月01日 星期三 12时47分55秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int t, n;
ll m;
int b[105];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %lld", &n, &m);
		int x;
		for (int i = 1; i <= n; i++) scanf("%d %d", &x, &b[i]);
		sort(b + 1, b + 1 + n);
		ll cnt = 1, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt * (b[i] + 1) <= m)
				cnt *= (b[i] + 1), ans++;
			else
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
