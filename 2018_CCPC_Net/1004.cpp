//******************************************************************************
// File Name: 1004.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月25日 星期六 12时14分07秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int t;

int main()
{
	scanf("%d", &t);
	while (t--) {
		ll n, a;
		scanf("%lld %lld", &n, &a);
		if (n == 0)
			puts("-1 -1");
		else
		if (n == 1)
			printf("1 %lld\n", a + 1);
		else
		if (n == 2) {
			if (a == 2 || a == 1)
				puts("-1 -1");
			else
			if (a % 2 == 0) {
				ll c = (a / 2) * (a / 2) + 1, b = c - 2;
				printf("%lld %lld\n", b, c);
			}
			else {
				ll c = (1 + a * a) / 2, b = (a * a - 1) / 2;
				printf("%lld %lld\n", b, c);
			}
		}
		else
		if (n > 2)
			puts("-1 -1");
	}
	return 0;
}
