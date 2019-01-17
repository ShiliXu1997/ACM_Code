//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 13 Oct 2018 01:50:40 PM CST
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

const int MAXN = 1e5 + 5;

struct segment {
    int l, r, mn, mark;
};

int t, n, k;
int a[MAXN];
segment tree[MAXN << 2];

void push_down(int root)
{
    int &mark = tree[root].mark;
    if (mark) {
        tree[root << 1].mn += mark;
        tree[root << 1].mark += mark;
        tree[root << 1 | 1].mn += mark;
        tree[root << 1 | 1].mark += mark;
        mark = 0;
    }
}

void push_up(int root)
{
    tree[root].mn = min(tree[root << 1].mn, tree[root << 1 | 1].mn);
}

void build(int left, int right, int root)
{
    tree[root].l = left;
    tree[root].r = right;
    tree[root].mark = 0;
    if (left == right) {
        tree[root].mn = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, root << 1);
    build(mid + 1, right, root << 1 | 1);
    push_up(root);
}

int query(int left, int right, int root)
{
    if (left <= tree[root].l && tree[root].r <= right) return tree[root].mn;
    push_down(root);
    int ans = 0x3f3f3f3f, mid = (tree[root].l + tree[root].r) >> 1;
    if (left <= mid) ans = min(ans, query(left, right, root << 1));
    if (right >= mid + 1) ans = min(ans, query(left, right, root << 1 | 1));
    return ans;
}

void modify(int left, int right, int num, int root)
{
    if (left <= tree[root].l && tree[root].r <= right) {
        tree[root].mn += num;
        tree[root].mark += num;
        return;
    }
    push_down(root);
    int mid = (tree[root].l + tree[root].r) >> 1;
    if (left <= mid) modify(left, right, num, root << 1);
    if (right >= mid + 1) modify(left, right, num, root << 1 | 1);
    push_up(root);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, n, 1);
        ll ans = 0;
        for (int i = 1; i <= n - k + 1; i++) {
            int diff = query(i, i + k - 1, 1);
            if (!diff) continue;
            modify(i, i + k - 1, -diff, 1);
            ans += diff;
        }
        printf("%lld\n", ans);
    }
	return 0;
}
