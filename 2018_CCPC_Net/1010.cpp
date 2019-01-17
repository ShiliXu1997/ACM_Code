//******************************************************************************
// File Name: 1010.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月25日 星期六 15时16分02秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

struct node {
	int x, y, v;
	
	node() {}
	node(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}

	bool operator<(const node &another) const
	{
		if (x == another.x) return y < another.y;
		return x < another.x;
	}
};

bool cmp(const node &a, const node &b)
{
	if (a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}

struct segment {
	int l, r, mx;
};

int t, n;
int dp[MAXN]; node nd[MAXN], p[MAXN];
segment tree[MAXN << 2];

void update(int rt)
{
	tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx);
}

void build(int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	if (l == r) {
		tree[rt].mx = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	update(rt);
}

void modify(int pos, int num, int rt)
{
	if (tree[rt].l == tree[rt].r) {
		tree[rt].mx = num;
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (pos <= mid) modify(pos, num, rt << 1);
	if (pos >= mid + 1) modify(pos, num, rt << 1 | 1);
	update(rt);
}

int query(int l, int r, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].mx;
	int ans = 0;
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (l <= mid) ans = max(ans, query(l, r, rt << 1));
	if (r >= mid + 1) ans = max(ans, query(l, r, rt << 1 | 1));
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &nd[i].x, &nd[i].y, &nd[i].v);
			p[i].x = nd[i].x, p[i].y = nd[i].y, p[i].v = nd[i].v;
		}
		memset(dp, 0, sizeof(dp));
		sort(nd + 1, nd + 1 + n, cmp);
		sort(p + 1, p + 1 + n);
		build(1, n, 1);
		for (int i = 1; i <= n; i++) {
			int pos = (lower_bound(p + 1, p + 1 + n, node(nd[i].x, 0, 0)) - p) - 1;
			dp[i] = max(dp[i], query(1, pos, 1) + nd[i].v);
			modify(lower_bound(p + 1, p + 1 + n, nd[i]) - p, dp[i], 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
