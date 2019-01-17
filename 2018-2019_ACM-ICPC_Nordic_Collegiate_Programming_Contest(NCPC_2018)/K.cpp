//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 27 Oct 2018 06:36:50 PM CST
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

const int MAXN = 2505, MOD = 1e9 + 7;

int n, k;
ll C[MAXN][MAXN];

void init()
{
    C[0][0] = 1; C[0][1] = 0;
    for (int i = 1; i <= 2500; i++) {
        C[i][0] = 1; C[i][i + 1] = 0;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}

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
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
    }
    init();
    ll ans = 0;
    for (int i = k, j = 1; i >= 2; i--, j = -j)
        ans = ((ans + (ll)j * C[k][i] * i % MOD * qpow(i - 1, n - 1, MOD) % MOD) % MOD + MOD) % MOD;
    printf("%lld\n", ans);
	return 0;
}
