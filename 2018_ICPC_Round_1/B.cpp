//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月30日 星期四 13时22分55秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

struct segment {
	int l, r, cnt_0, cnt_1;
	int mark;
};

int n, m;
int a[MAXN], l[MAXN], r[MAXN];
segment tree[MAXN << 2];

void update(int rt)
{
	tree[rt].cnt_0 = tree[rt << 1].cnt_0 + tree[rt << 1 | 1].cnt_0;
	tree[rt].cnt_1 = tree[rt << 1].cnt_1 + tree[rt << 1 | 1].cnt_1;
}

void push_down(int rt)
{
	int l = tree[rt].l, r = tree[rt].r, mid = (l + r) >> 1;
	if (!tree[rt].mark) {
		tree[rt << 1].cnt_0 = (mid - l + 1);
		tree[rt << 1 | 1].cnt_0 = (r - mid);
		tree[rt << 1].cnt_1 = tree[rt << 1 | 1].cnt_1 = 0;
		tree[rt << 1].mark = tree[rt << 1 | 1].mark = 0;
		tree[rt].mark = -1;
	}
	if (tree[rt].mark == 1) {
		tree[rt << 1].cnt_1 = (mid - l + 1);
		tree[rt << 1 | 1].cnt_1 = (r - mid);
		tree[rt << 1].cnt_0 = tree[rt << 1 | 1].cnt_0 = 0;
		tree[rt << 1].mark = tree[rt << 1 | 1].mark = 1;
		tree[rt].mark = -1;
	}
}

void build(int ans, int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].mark = -1;
	if (l == r) {
		if (a[l] == ans) tree[rt].cnt_0 = tree[rt].cnt_1 = 0;
		if (a[l] < ans) tree[rt].cnt_0 = 1, tree[rt].cnt_1 = 0;
		if (a[l] > ans) tree[rt].cnt_1 = 1, tree[rt].cnt_0 = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(ans, l, mid, rt << 1);
	build(ans, mid + 1, r, rt << 1 | 1);
	update(rt);
}

pair<int, int> query(int l, int r, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) return make_pair(tree[rt].cnt_0, tree[rt].cnt_1);
	push_down(rt);
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	pair<int, int> ans, lson, rson;
	if (l <= mid) lson = query(l, r, rt << 1);
	if (r >= mid + 1) rson = query(l, r, rt << 1 | 1);
	ans = make_pair(lson.first + rson.first, lson.second + rson.second);
	return ans;
}

void modify(int l, int r, int num, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) {
		tree[rt].mark = num;
		if (num == 0) tree[rt].cnt_0 = (tree[rt].r - tree[rt].l + 1), tree[rt].cnt_1 = 0;
		else
		if (num == 1) tree[rt].cnt_0 = 0, tree[rt].cnt_1 = (tree[rt].r - tree[rt].l + 1);
		else
			tree[rt].cnt_0 = tree[rt].cnt_1 = 0;
		return;
	}
	push_down(rt);
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (l <= mid)
		modify(l, r, num, rt << 1);
	if (r >= mid + 1)
		modify(l, r, num, rt << 1 | 1);
	update(rt);
}

int check(int mid)
{
	build(mid, 1, n, 1);
	for (int i = 1; i <= m; i++) {
		if (l[i] == r[i]) continue;
		int left, right;
		if (l[i] < r[i]) {
			left = l[i], right = r[i];
			pair<int, int> q = query(left, right, 1);
			if (left <= left + q.first - 1) modify(left, left + q.first - 1, 0, 1);
			if (right - q.second + 1 <= right) modify(right - q.second + 1, right, 1, 1);
			if (right - left + 1 > q.first + q.second) modify(left + q.first, left + q.first, -2, 1);
		}
		if (l[i] > r[i]) {
			left = r[i], right = l[i];
			pair<int, int> q = query(left, right, 1);
			if (left <= left + q.second - 1) modify(left, left + q.second - 1, 1, 1);
			if (right - q.first + 1 <= right) modify(right - q.first + 1, right, 0, 1);
			if (right - left + 1 > q.first + q.second) modify(left + q.second, left + q.second, -2, 1);
		}
	}
	int zhongjian = (1 + n) >> 1;
	pair<int, int> get = query(zhongjian, zhongjian, 1);
	if (get.first == 0 && get.second == 0) return 0;
	if (get.first == 1)
		return -1;
	else
		return 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d %d", &l[i], &r[i]);
	int left = 1, right = n, ans = 0;
	while (left < right) {
		int mid = (left + right) >> 1;
		int now = check(mid);
		if (now == 0) {
			ans = mid;
			break;
		}
		if (now > 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (left == right) ans = left;
	printf("%d\n", ans);
	return 0;
}
