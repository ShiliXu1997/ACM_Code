//******************************************************************************
// File Name: HDU_1796.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月05日 星期日 10时21分43秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

set<int> st;
int a[25];
int n, m;

ll gcd(ll a, ll b)
{
	return (!b ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		int x;
		st.clear();
		for (int i = 1; i <= m; i++) scanf("%d", &x), st.insert(x);
		m = 0;
		for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
			if (*it) a[++m] = *it;
		ll ans = 0, all = 1 << m;
		for (int i = 1; i < all; i++) {
			int cnt = 0, now = 1;
			for (int j = 0; j < m; j++)
				if (i & (1 << j)) cnt++, now = lcm(now, a[j + 1]);
			ans += (cnt & 1 ? 1 : -1) * (n / now);
			if (n % now == 0) ans -= (cnt & 1 ? 1 : -1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
