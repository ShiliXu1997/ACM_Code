//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 01:33:56 PM CST
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

const int MAXN = 2e5 + 5;

struct left_segment {
    int l, r, mx;
};

struct right_segment {
    int l, r, mn;
};

int n, q;
left_segment left_tree[MAXN << 2];
right_segment right_tree[MAXN << 2];

void left_push_up(int rt)
{
    left_tree[rt].mx = max(left_tree[rt << 1].mx, left_tree[rt << 1 | 1].mx);
}

void left_build(int l, int r, int rt)
{
    left_tree[rt].l = l;
    left_tree[rt].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    left_build(l, mid, rt << 1);
    left_build(mid + 1, r, rt << 1 | 1);
    left_push_up(rt);
}

void left_modify(int index, int num, int rt)
{
    if (left_tree[rt].l == left_tree[rt].r) {
        left_tree[rt].mx = num;
        return;
    }
    int mid = (left_tree[rt].l + left_tree[rt].r) >> 1;
    if (index <= mid)
        left_modify(index, num, rt << 1);
    else
        left_modify(index, num, rt << 1 | 1);
    left_push_up(rt);
}

int left_query(int l, int r, int rt)
{
    if (l <= left_tree[rt].l && left_tree[rt].r <= r) return left_tree[rt].mx;
    int mid = (left_tree[rt].l + left_tree[rt].r) >> 1, ans = -0x3f3f3f3f;
    if (l <= mid) ans = max(ans, left_query(l, r, rt << 1));
    if (r >= mid + 1) ans = max(ans, left_query(l, r, rt << 1 | 1));
    return ans;
}

void right_push_up(int rt)
{
    right_tree[rt].mn = min(right_tree[rt << 1].mn, right_tree[rt << 1 | 1].mn);
}

void right_build(int l, int r, int rt)
{
    right_tree[rt].l = l;
    right_tree[rt].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    right_build(l, mid, rt << 1);
    right_build(mid + 1, r, rt << 1 | 1);
    right_push_up(rt);
}

void right_modify(int index, int num, int rt)
{
    if (right_tree[rt].l == right_tree[rt].r) {
        right_tree[rt].mn = num;
        return;
    }
    int mid = (right_tree[rt].l + right_tree[rt].r) >> 1;
    if (index <= mid)
        right_modify(index, num, rt << 1);
    else
        right_modify(index, num, rt << 1 | 1);
    right_push_up(rt);
}

int right_query(int l, int r, int rt)
{
    if (l <= right_tree[rt].l && right_tree[rt].r <= r) return right_tree[rt].mn;
    int mid = (right_tree[rt].l + right_tree[rt].r) >> 1, ans = 0x3f3f3f3f;
    if (l <= mid) ans = min(ans, right_query(l, r, rt << 1));
    if (r >= mid + 1) ans = min(ans, right_query(l, r, rt << 1 | 1));
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    left_build(1, n, 1);
    right_build(1, n, 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        left_modify(i, l, 1);
        right_modify(i, r, 1);
    }
    char mes[2];
    for (int i = 1; i <= q; i++) {
        scanf("%s", mes);
        if (mes[0] == 'C') {
            int who, l, r;
            scanf("%d %d %d", &who, &l, &r);
            left_modify(who, l, 1);
            right_modify(who, r, 1);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            int mx = left_query(l, r, 1), mn = right_query(l, r, 1);
            if (mx > mn)
                printf("0\n");
            else
                printf("%d\n", mn - mx + 1);
        }
    }
	return 0;
}
