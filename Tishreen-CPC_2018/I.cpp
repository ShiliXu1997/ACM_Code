//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 01:49:40 PM CST
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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;

int t, n, q;
int odd[MAXN], even[MAXN];

ll qpow(ll a, ll b, ll c)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        odd[0] = even[0] = 0;
        for (int i = 1; i <= n; i++) {
            odd[i] = odd[i - 1];
            even[i] = even[i - 1];
            int x;
            scanf("%d", &x);
            if (x & 1)
                odd[i]++;
            else
                even[i]++;
        }
        while (q--) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            ll cnt = qpow(2, odd[r] - odd[l - 1], MOD) - 1;
            if (k)
                printf("%lld\n", cnt);
            else
                printf("%lld\n", ((qpow(2, r - l + 1, MOD) - 1 - cnt) % MOD + MOD) % MOD);
        }
    }
	return 0;
}
