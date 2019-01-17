//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 13 Oct 2018 04:17:59 PM CST
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

const int MAXN = 105, MOD = 1e9 + 7;

char s[6][MAXN];
ll dp[6][MAXN];
ll inv[6];
ll ans;

void solve(int st)
{
    if(st == 5) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 100; i++)
            if (s[1][i] == '1') dp[1][i] = 1;
        for (int i = 2; i <= 5; i++) {
            for (int j = 1; j <= 100; j++)
                if (s[i][j] == '1') {
                    for (int k = 1; k <= j - 1; k++) dp[i][j] += dp[i - 1][k], dp[i][j] %= MOD;
                }
        }
        for (int i = 1; i <= 100; i++) ans += dp[5][i], ans %= MOD;
    }
    else {
        for (int i = st; i <= 5; i++) {
            swap(s[st], s[i]);
            solve(st + 1);
            swap(s[st], s[i]);
        }
    }
}

ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    for (int i = 1; i <= 5; i++) inv[i] = qpow(i, MOD - 2);
    ll fuck = 1;
    for (int i = 1; i <= 5; i++) fuck = fuck * (96 - i) % MOD;
    for (int i = 1; i <= 5; i++) fuck = fuck * (91 - i) % MOD * inv[i] % MOD;
    for (int i = 1; i <= 5; i++) fuck = fuck * (86 - i) % MOD * inv[i] % MOD;
    while (scanf("%s", s[1] + 1) == 1) {
        for (int i = 2; i <= 5; i++) scanf("%s", s[i] + 1);
        ans = 0;
        solve(1);
        ans = ans * fuck % MOD;
        printf("%lld\n", ans);
    }
	return 0;
}
