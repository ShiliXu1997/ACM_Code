//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 04 Oct 2018 03:23:17 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n;

ll get(ll x)
{
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    scanf("%lld", &n);
    if (n <= 9)
        printf("%lld\n", n);
    else {
        ll now = 9;
        while (now * 10 + 9 <= n) now = now * 10 + 9;
        int ans = get(now) + get(n - now);
        printf("%d\n", ans);
    }
	return 0;
}
