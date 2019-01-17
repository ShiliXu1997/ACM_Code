//******************************************************************************
// File Name: SPOJ_DQUERY.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 07 Nov 2018 07:31:19 PM CST
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

const int MAXN = 3e4 + 5;

struct segment {
    int lson, rson, sum;
};

int n, q, cnt;
int a[MAXN], root[MAXN], done[(int)1e6 + 5];
segment tree[MAXN * 21];

void push_up(int rt)
{
    tree[rt].sum = tree[tree[rt].lson].sum + tree[tree[rt].rson].sum;
}

void build(int l, int r, int &rt)
{
    rt = ++cnt;
    tree[rt].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, tree[rt].lson);
    build(mid + 1, r, tree[rt].rson);
}

void modify(int pos, int num, int l, int r, int pre, int &rt)
{
    rt = ++cnt;
    tree[rt] = tree[pre];
    if (l == r) {
        tree[rt].sum += num;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, num, l, mid, tree[pre].lson, tree[rt].lson);
    if (pos >= mid + 1) modify(pos, num, mid + 1, r, tree[pre].rson, tree[rt].rson);
    push_up(rt);
}

int query(int pos, int l, int r, int rt)
{
    if (l == r) return tree[rt].sum;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query(pos, l, mid, tree[rt].lson) + tree[tree[rt].rson].sum;
    else
        return query(pos, mid + 1, r, tree[rt].rson);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cnt = 0;
    build(1, n, root[0]);
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++) {
        if (!done[a[i]])
            modify(i, 1, 1, n, root[i - 1], root[i]);
        else {
            modify(done[a[i]], -1, 1, n, root[i - 1], root[i]);
            modify(i, 1, 1, n, root[i], root[i]);
        }
        done[a[i]] = i;
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = query(l, 1, n, root[r]);
        printf("%d\n", ans);
    }
	return 0;
}
