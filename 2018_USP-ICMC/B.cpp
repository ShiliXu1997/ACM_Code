//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 12:37:23 AM CST
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

const int MAXN = 1e6 + 5, S = 131, MOD = 1e9 + 7;

int n, len;
char s[MAXN];
ll p[MAXN], inv[MAXN], sum[MAXN];

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

void init_hash()
{
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * S % MOD;
    inv[MAXN - 1] = qpow(p[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = inv[i + 1] * S % MOD;
    sum[0] = 0;
    for (int i = 1; i <= len; i++) sum[i] = (sum[i - 1] + (s[i] - 'a' + 1) * p[i - 1]) % MOD;
}

ll get_hash(int l, int r)
{
    return ((sum[r] - sum[l - 1]) * inv[l - 1] % MOD + MOD) % MOD;
}

bool check(int pos)
{
    int l = -1, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (get_hash(1, 1 + mid) == get_hash(pos, pos + mid))
            l = mid;
        else
            r = mid;
    }
    if (1 + l == n) return true;
    return s[1 + l + 1] <= s[pos + l + 1];
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) s[n + i] = s[i];
    len = 2 * n;
    init_hash();
    bool ans = true;
    for (int i = 2; i <= n; i++) ans &= check(i);
    printf("%s\n", ans ? "Yes" : "No");
	return 0;
}
