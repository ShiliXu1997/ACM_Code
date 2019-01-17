//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 17 Oct 2018 06:47:14 PM CST
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

const int MAXN = 1e4 + 5;

struct linear_basis {
    ll b[61];

    linear_basis()
    {
        memset(b, 0, sizeof(b));
    }

    void init()
    {
        memset(b, 0, sizeof(b));
    }

    bool insert(ll x)
    {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                if (!b[i]) {
                    b[i] = x;
                    break;
                }
                x ^= b[i];
            }
        }
        return x > 0;
    }

    ll get_max()
    {
        ll ans = 0;
        for (int i = 60; i >= 0; i--)
            if ((ans ^ b[i]) > ans) ans ^= b[i];
        return ans;
    }

    ll get_min()
    {
        for (int i = 0; i <= 60; i++)
            if (b[i]) return b[i];
        return 0;
    }

    linear_basis& operator=(const linear_basis &another)
    {
        for (int i = 60; i >= 0; i--) b[i] = another.b[i];
        return *this;
    }

    linear_basis operator+(const linear_basis &another) const
    {
        linear_basis ans;
        for (int i = 60; i >= 0; i--) ans.b[i] = b[i];
        for (int i = 60; i >= 0; i--)
            if (another.b[i]) ans.insert(another.b[i]);
        return ans;
    }
};

struct segment {
    int l, r;
    linear_basis ba;
};

int t, n, q, k;
ll a[MAXN];
segment tree[MAXN << 2];

void push_up(int root)
{
    tree[root].ba = tree[root << 1].ba + tree[root << 1 | 1].ba;
}

void build(int left, int right, int root)
{
    tree[root].l = left;
    tree[root].r = right;
    if (left == right) {
        tree[root].ba.init();
        tree[root].ba.insert(a[left]);
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, root << 1);
    build(mid + 1, right, root << 1 | 1);
    push_up(root);
}

linear_basis query(int left, int right, int root)
{
    if (left <= tree[root].l && tree[root].r <= right) return tree[root].ba;
    int mid = (tree[root].l + tree[root].r) >> 1;
    linear_basis ans;
    if (left <= mid) ans = ans + query(left, right, root << 1);
    if (right >= mid + 1) ans = ans + query(left, right, root << 1 | 1);
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &q, &k);
        ll _k = 0;
        for (int i = 0; i <= 60; i++)
            if (!((ll)k >> i & 1)) _k |= (1ll << i);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            a[i] &= _k;
        }
        build(1, n, 1);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            linear_basis base = query(l, r, 1);
            ll ans = base.get_max() | k;
            printf("%lld\n", ans);
        }
    }
	return 0;
}
