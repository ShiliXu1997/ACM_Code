//******************************************************************************
// File Name: BZOJ_4017.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 15 Oct 2018 03:28:19 PM CST
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

const int MAXN = 1e5 + 5, MOD = 998244353;

int n, mx;
int a[MAXN];
ll s[MAXN], now[MAXN], b[MAXN], c[MAXN], g[40];
int cnt[MAXN][20];

int lowbit(int x)
{
    return x & -x;
}

void modify(int x, int num)
{
    while (x <= mx) {
        c[x] += num;
        x += lowbit(x);
    }
}

ll sum(int x)
{
    ll ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans1 = 0, ans2 = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= 19; i++) if (a[1] >> i & 1) cnt[1][i]++;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 19; j++) {
            if (a[i] >> j & 1)
                cnt[i][j] = i - cnt[i - 1][j];
            else
                cnt[i][j] = cnt[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 19; j++) ans1 = (ans1 + (1ll << j) * cnt[i][j]) % MOD;
	s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = (ll)a[i] + s[i - 1];
    memset(g, 0, sizeof(g));
    for (int k = 0; k <= 38; k++) {
        for (int i = 0; i <= n; i++) now[i] = b[i + 1] = s[i] % (1ll << (k + 1));
        sort(b + 1, b + 2 + n);
        mx = unique(b + 1, b + 2 + n) - b - 1;
        memset(c, 0, sizeof(c));
        int p;
        for (int i = 0; i <= n; i++) {
            p = lower_bound(b + 1, b + 1 + mx, now[i] + (1ll << k)) - b;
            if (p == mx + 1 || b[p] != now[i] + (1ll << k)) p--;
            g[k] += sum(p);
            if (now[i] >= (1ll << k)) {
                p = lower_bound(b + 1, b + 1 + mx, now[i] - (1ll << k)) - b;
                if (b[p] != now[i] - (1ll << k)) p--;
                g[k] += sum(p);
            }
            p = lower_bound(b + 1, b + 1 + mx, now[i]) - b;
            g[k] -= sum(p);
            modify(p, 1);
        }
    }
    for (int i = 0; i <= 38; i++) if (g[i] & 1) ans2 += (1ll << i);
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
