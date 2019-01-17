//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 08 Nov 2018 08:17:21 PM CST
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

const int MAXN = 3e4 + 5;;

struct query {
    int l, r, id, block;
    
    bool operator<(const query &another) const
    {
        if (block == another.block) return r < another.r;
        return block < another.block;
    }
};

int n, q, s, now;
int a[MAXN], b[MAXN], cnt[MAXN], tot[MAXN], ans[MAXN];
query qu[MAXN];

void modify(int pos, int num)
{
    if (num == 1) {
        cnt[a[pos]]++;
        tot[cnt[a[pos]]]++;
        if (tot[cnt[a[pos]]] >= cnt[a[pos]] && cnt[a[pos]] > now) now = cnt[a[pos]];
    }
    else {
        tot[cnt[a[pos]]]--;
        cnt[a[pos]]--;
        if (tot[now] < now) now--;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    s = (int)sqrt(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
	for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qu[i].l, &qu[i].r);
        qu[i].id = i;
        qu[i].block = i / s;
    }
    sort(qu + 1, qu + 1 + q);
    memset(cnt, 0, sizeof(cnt));
    memset(tot, 0, sizeof(tot));
    now = 0;
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        while (r < qu[i].r) modify(++r, 1);
        while (r > qu[i].r) modify(r--, -1);
        while (l < qu[i].l) modify(l++, -1);
        while (l > qu[i].l) modify(--l, 1);
        ans[qu[i].id] = now;
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
