//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月17日 星期五 22时55分42秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;

int main()
{
	scanf("%lld %lld", &n, &k);
	ll ans;
	if (n + n - 1 < k || 3 > k)
		ans = 0;
	else {
		ll mn = k / 2, mx = k / 2;
		if (k & 1)
			mx++;
		else
			mn--, mx++;
		ans = min(n - mx + 1, mn);
	}
	printf("%lld\n", ans);
	return 0;
}
