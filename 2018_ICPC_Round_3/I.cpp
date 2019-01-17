//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月05日 星期三 16时20分44秒
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

ll L, R;

ll cal(ll mid)
{
	ll s1 = 0, s2 = 0, s3 = 0;
	if (mid % 3 == 0) s1 = 1;
	s2 = (mid - 1) / 2 - s1;
	s3 = ((mid - 1) * (mid - 2) / 2 - s1 - 3 * s2) / 6;
	return s1 + s2 + s3;
}

ll get(ll t)
{
	if (t == 0) return 2;
	ll l = 3, r = 10000000000, ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (cal(mid) <= t)
			l = mid + 1, ans = mid;
		else
			r = mid - 1;
	}
	return ans;
}

int main()
{
	scanf("%lld %lld", &L, &R);
	ll left = get(L - 1), right = get(R);
	printf("%lld\n", right - left);
	return 0;
}
