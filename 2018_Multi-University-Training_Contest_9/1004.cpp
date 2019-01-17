//******************************************************************************
// File Name: 1004.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月21日 星期二 16时12分06秒
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

ll gcd(ll a, ll b)
{
    if (a < 0) a = -a;
	if (b < 0) b = -b;
	return (!b ? a : gcd(b, a % b));
}

struct fraction{
    ll num, den;

    fraction() {}
    fraction(ll _num, ll _den) : num(_num), den(_den) {}
    void reduce()
    {
        ll d = gcd(num, den);
        if (d > 1) num /= d, den /= d;
    }
};

ll t, a, b, c, ap, bp, cp;

int main()
{
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        scanf("%lld %lld %lld", &ap, &bp, &cp);
        ll n = a + b + c;
        fraction ans = fraction(a * (bp - cp) + b * (cp - ap) + c * (ap - bp), n);
        ans.reduce();
        printf("%lld", ans.num);
        if (ans.den > 1) printf("/%lld", ans.den);
        puts("");
    }
    return 0;
}
