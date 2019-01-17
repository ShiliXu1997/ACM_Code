//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 29 Oct 2018 08:06:29 PM CST
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
typedef pair<ll, ll> pll;
#define x first
#define y second

const int MAXN = 1e5 + 5;
const ll S1 = 15485867, S2 = 32452843, MOD1 = 1e9 + 21, MOD2 = 1e9 + 9;
const pll S = pll(S1, S2), MOD = pll(MOD1, MOD2);

ostream& operator<<(ostream &os, pll h) {return os << "(" << h.x << ", " << h.y << ")";}

pll operator+(const pll a, const ll b) {return pll(a.x + b, a.y + b);}
pll operator-(const pll a, const ll b) {return pll(a.x - b, a.y - b);}
pll operator*(const pll a, const ll b) {return pll(a.x * b, a.y * b);}
pll operator+(const pll a, const pll b) {return pll(a.x + b.x, a.y + b.y);}
pll operator-(const pll a, const pll b) {return pll(a.x - b.x, a.y - b.y);}
pll operator*(const pll a, const pll b) {return pll(a.x * b.x, a.y * b.y);}
pll operator%(const pll a, const pll b) {return pll(a.x % b.x, a.y % b.y);}

int n, m;
int a[11][MAXN], pos[11][MAXN];
pll p[MAXN], inv[MAXN];
pll sum[11][MAXN];

pll qpow(pll a, pll b, pll c)
{
    ll ansx = 1, ansy = 1;
    while (b.x) {
        if (b.x & 1) ansx = ansx * a.x % c.x;
        a.x = a.x * a.x % c.x;
        b.x >>= 1;
    }
    while (b.y) {
        if (b.y & 1) ansy = ansy * a.y % c.y;
        a.y = a.y * a.y % c.y;
        b.y >>= 1;
    }
    return pll(ansx, ansy);
}

void init_hash()
{
    p[0] = pll(1, 1);
    for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * S % MOD;
    inv[MAXN - 1] = qpow(p[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = inv[i + 1] * S % MOD;
    for (int i = 1; i <= m; i++) {
        sum[i][0] = pll(0, 0);
        for (int j = 1; j <= n; j++) sum[i][j] = (sum[i][j - 1] + p[j - 1] * a[i][j] % MOD) % MOD;
    }
}

pll get_hash(int i, int l, int r)
{
    return ((sum[i][r] - sum[i][l - 1]) * inv[l - 1] % MOD + MOD) % MOD;
}

bool check(int i, int len)
{
    bool flag = true;
    pll miao = get_hash(1, i, i + len - 1);
    for (int j = 2; j <= m && flag; j++) {
        int w = pos[j][a[1][i]];
        if (n < w + len - 1 || miao != get_hash(j, w, w + len - 1)) flag = false;
    }
    return flag;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]), pos[i][a[i][j]] = j;
	init_hash();
    ll ans = 0;
    for (int i = 1, nxt; i <= n; i += nxt) {
        nxt = 1;
        int l = 2, r = n - i + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid))
                nxt = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        ans += (ll)nxt * (nxt + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
