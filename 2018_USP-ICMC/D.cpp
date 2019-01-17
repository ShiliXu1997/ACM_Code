//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 06 Oct 2018 12:15:42 PM CST
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

ll n, rs, cs, rt, ct;

int main()
{
    scanf("%lld %lld %lld %lld %lld", &n, &rs, &cs, &rt, &ct);
    ll base = llabs(rs - rt) + llabs(cs - ct);
    ll ans = (base != 0 && n >= base);
    if (n >= base) ans += (n - base) >> 1;
    printf("%lld\n", ans);
	return 0;
}
