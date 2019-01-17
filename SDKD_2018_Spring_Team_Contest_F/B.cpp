//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 23时03分12秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

struct segment {
	int l, r, val;
};

int h, w, n;
segment tree[MAXN << 2];

void build(int left, int right, int root)
{
	tree[root].l = left;
	tree[root].r = right;
	if (left == right) {
		tree[root].val = w;
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	tree[root].val = max(tree[root << 1].val, tree[root << 1 | 1].val);
}

void modify(int pos, int num, int root)
{
	if (tree[root].l == tree[root].r) {
		tree[root].val += num;
		return;
	}
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (pos <= mid)
		modify(pos, num, root << 1);
	else
		modify(pos, num, root << 1 | 1);
	tree[root].val = max(tree[root << 1].val, tree[root << 1 | 1].val);
}

int query(int num, int root)
{
	if (tree[root].l == tree[root].r) {
		if (num > tree[root].val) return -1;
		return tree[root].l;
	}
	if (tree[root << 1].val >= num)
		return query(num, root << 1);
	else
		return query(num, root << 1 | 1);
}

int main()
{
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	scanf("%d %d %d", &h, &w, &n);
	build(1, min(n, h), 1);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		int pos = query(x, 1);
		if (pos != -1) modify(pos, -x, 1);
		printf("%d\n", pos);
	}
	return 0;
}
