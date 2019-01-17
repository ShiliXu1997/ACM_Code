//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月04日 星期二 22时20分45秒
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

int t;
ll a, b, c, d;

ll gcd(ll a, ll b)
{
	return (!b ? a : gcd(b, a % b));
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		bool ans = true;
		if (a < b)
			ans = false;
		else {
			if (d < b)
				ans = false;
			else {
				if (c < b) {
					ll g = gcd(b, d);
					ll mn = (a - b) / g, mx = (a - c - 1) / g;
					if (mx - mn > 0) ans = false;
				}
			}
		}
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}
