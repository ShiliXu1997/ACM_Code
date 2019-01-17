//******************************************************************************
// File Name: BZOJ_2038.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 08 Nov 2018 03:14:46 PM CST
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
typedef pair<int, int> pii;
#define x first
#define y second

const int MAXN = 5e4 + 5;

struct query {
    int l, r, id, block;

    bool operator<(const query &another) const
    {
        if (block == another.block) return r < another.r;
        return block < another.block;
    }
};

int n, q, s;
ll sum;
int a[MAXN], cnt[MAXN];
ll ans_a[MAXN], ans_b[MAXN];
query qu[MAXN];

ll gcd(ll a, ll b)
{
    return (!b ? a : gcd(b, a % b));
}

void modify(int pos, int num)
{
    sum += 2 * cnt[a[pos]] * num + num * num - num;
    cnt[a[pos]] += num;
}

int main()
{
    scanf("%d %d", &n, &q);
    s = (int)sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qu[i].l, &qu[i].r);
        qu[i].id = i;
        qu[i].block = qu[i].l / s;
    }
    sort(qu + 1, qu + 1 + q);
    sum = 0;
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        while (r < qu[i].r) modify(++r, 1);
        while (r > qu[i].r) modify(r--, -1);
        while (l < qu[i].l) modify(l++, -1);
        while (l > qu[i].l) modify(--l, 1);
        ans_a[qu[i].id] = sum;
        ans_b[qu[i].id] = (ll)(qu[i].r - qu[i].l + 1) * (qu[i].r - qu[i].l);
    }
    for (int i = 1; i <= q; i++) {
        int tmp = gcd(ans_a[i], ans_b[i]);
        ans_a[i] /= tmp;
        ans_b[i] /= tmp;
        printf("%lld/%lld\n", ans_a[i], ans_b[i]);
    }
	return 0;
}
