//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 15 Sep 2018 12:17:50 PM CST
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;

int t;
char s[MAXN];

ll qpow(ll a, ll b, ll c)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return ans;
}

int main()
{
    ll inv_2 = qpow(2, MOD - 2, MOD);
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int len = strlen(s);
        ll ans = qpow(2, s[0] - '0', MOD);
        for (int i = 1; i < len; i++) {
            ans = qpow(ans, 10, MOD) * qpow(2, (s[i] - '0'), MOD) % MOD;
        }
        printf("%lld\n", ans * inv_2 % MOD);
    }
    return 0;
}
