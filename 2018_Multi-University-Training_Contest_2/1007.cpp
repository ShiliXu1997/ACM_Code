//******************************************************************************
// File Name: 1007.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月26日 星期四 14时00分47秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 101000;

struct segment {
	int sum, min, flag;
};

int n, q;
int b[MAXN];
segment tree[MAXN << 2];

void push_down(int rt)
{
	if (tree[rt].flag) {
		tree[rt << 1].min += tree[rt].flag;
		tree[rt << 1].flag += tree[rt].flag;
		tree[rt << 1 | 1].min += tree[rt].flag;
		tree[rt << 1 | 1].flag += tree[rt].flag;
		tree[rt].flag = 0;
	}
}

void update(int rt)
{
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
	tree[rt].min = min(tree[rt << 1].min, tree[rt << 1 | 1].min);
}

void build(int left, int right, int rt)
{
	tree[rt].flag = 0;
	if (left == right) {
		tree[rt].min = b[left];
		tree[rt].sum = 0;
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, rt << 1);
	build(mid + 1, right, rt << 1 | 1);
	update(rt);
}

void modify(int l, int r, int x, int left, int right, int rt)
{
	int mid = (left + right) >> 1;
	if (l <= left && right <= r) {
		tree[rt].min += x;
		tree[rt].flag += x;
		if (!tree[rt].min) {
			if (left == right) {
				tree[rt].sum++;
				tree[rt].min = b[left];
				return;
			}
			push_down(rt);
			if (!tree[rt << 1].min) modify(l, r, 0, left, mid, rt << 1);
			if (!tree[rt << 1 | 1].min) modify(l, r, 0, mid + 1, right, rt << 1 | 1);
			update(rt);
		}
		return;
	}
	push_down(rt);
	if (l <= mid) modify(l, r, x, left, mid, rt << 1);
	if (r >= mid + 1) modify(l, r, x, mid + 1, right, rt << 1 | 1);
	update(rt);
}

int query(int l, int r, int left, int right, int rt)
{
	if (l <= left && right <= r) return tree[rt].sum;
	push_down(rt);
	int mid = (left + right) >> 1;
	int ans = 0;
	if (l <= mid) ans += query(l, r, left, mid, rt << 1);
	if (r >= mid + 1) ans += query(l, r, mid + 1, right, rt << 1 | 1);
	return ans;
}

int main()
{
	while (scanf("%d %d", &n, &q) == 2) {
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		build(1, n, 1);
		while (q--) {
			char mes[20];
			int l, r;
			scanf("%s %d %d", mes, &l, &r);
			if (mes[0] == 'a')
				modify(l, r, -1, 1, n, 1);
			else {
				int ans = query(l, r, 1, n, 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
