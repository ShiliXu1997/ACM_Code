//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月13日 星期五 17时54分50秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 20005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct segment {
	ll sum, min, max, add, set;
};

ll r, c, m;
segment tree[22][MAXN << 2];

void push_up(int root, int index)
{
	tree[index][root].sum = tree[index][root << 1].sum + tree[index][root << 1 | 1].sum;
	tree[index][root].min = min(tree[index][root << 1].min, tree[index][root << 1 | 1].min);
	tree[index][root].max = max(tree[index][root << 1].max, tree[index][root << 1 | 1].max);
}

void push_down(int left, int right, int root, int index)
{
	int mid = (left + right) >> 1;
	if (tree[index][root].set != -1) {
		ll set = tree[index][root].set;
		tree[index][root << 1].set = tree[index][root << 1 | 1].set = set;
		tree[index][root << 1].add = tree[index][root << 1 | 1].add = 0;
		tree[index][root << 1].sum = set  * (mid - left + 1);
		tree[index][root << 1 | 1].sum = set * (right - mid);
		tree[index][root << 1].min = tree[index][root << 1 | 1].min = set;
		tree[index][root << 1].max = tree[index][root << 1 | 1].max = set;
	}
	if(tree[index][root].add != 0) {
		ll add = tree[index][root].add;
		tree[index][root << 1].add += add;
		tree[index][root << 1 | 1].add += add;
		tree[index][root << 1].sum += add * (mid - left + 1);
		tree[index][root << 1 | 1].sum += add * (right - mid);
		tree[index][root << 1].min += add;
		tree[index][root << 1 | 1].min += add;
		tree[index][root << 1].max += add;
		tree[index][root << 1 | 1].max += add;
	}
	tree[index][root].set = -1;
	tree[index][root].add = 0;
}

void build(int left, int right, int root, int index)
{
	tree[index][root].add = 0;
	tree[index][root].set = -1;
	if (left == right) {
		tree[index][root].sum = tree[index][root].min = tree[index][root].max = 0;
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1, index);
	build(mid + 1, right, root << 1 | 1, index);
	push_up(root, index);
}

void add(int l, int r, ll val, int left, int right, int root, int index)
{
	int mid = (left + right) >> 1;
	if (l <= left && right <= r) {
		tree[index][root].sum += val * (right - left + 1);
		tree[index][root].max += val;
		tree[index][root].min += val;
		tree[index][root].add += val;
		return;
	}
	push_down(left, right, root, index);
	if (l <= mid) add(l, r, val, left, mid, root << 1, index);
	if (r >= mid + 1) add(l, r, val, mid + 1, right, root << 1 | 1, index);
	push_up(root, index);
}

void set(int l, int r, ll val, int left, int right, int root, int index)
{
	int mid = (left + right) >> 1;
	if (l <= left && right <= r) {
		tree[index][root].sum = val * (right - left + 1);
		tree[index][root].max = val;
		tree[index][root].min = val;
		tree[index][root].add = 0;
		tree[index][root].set = val;
		return;
	}
	push_down(left, right, root, index);
	if (l <= mid) set(l, r, val, left, mid, root << 1, index);
	if (r >= mid + 1) set(l, r, val, mid + 1, right, root << 1 | 1, index);
	push_up(root, index);
}

ll query_sum(int l, int r, int left, int right, int root, int index)
{
	if (l <= left && right <= r) return tree[index][root].sum;
	push_down(left, right, root, index);
	ll ans = 0;
	int mid = (left + right) >> 1;
	if (l <= mid) ans += query_sum(l, r, left, mid, root << 1, index);
	if (r >= mid + 1) ans += query_sum(l, r, mid + 1, right, root << 1 | 1, index);
	return ans;
}

ll query_min(int l, int r, int left, int right, int root, int index)
{
	if (l <= left && right <= r) return tree[index][root].min;
	push_down(left, right, root, index);
	ll ans = INF;
	int mid = (left + right) >> 1;
	if (l <= mid) ans = min(ans, query_min(l, r, left, mid, root << 1, index));
	if (r >= mid + 1) ans = min(ans, query_min(l, r, mid + 1, right, root << 1 | 1, index));
	return ans;
}

ll query_max(int l, int r, int left, int right, int root, int index)
{
	if (l <= left && right <= r) return tree[index][root].max;
	push_down(left, right, root, index);
	ll ans = -INF;
	int mid = (left + right) >> 1;
	if (l <= mid) ans = max(ans, query_max(l, r, left, mid, root << 1, index));
	if (r >= mid + 1) ans = max(ans, query_max(l, r, mid + 1, right, root << 1 | 1, index));
	return ans;
}

int main()
{
	while (scanf("%lld %lld %lld", &r, &c, &m) == 3) {
		for (int i = 1; i <= r; i++) build(1, c, 1, i);
		while (m--) {
			int mes, x_1, x_2, y_1, y_2;
			ll v;
			scanf("%d", &mes);
			if (mes == 1) {
				scanf("%d %d %d %d %lld", &x_1, &y_1, &x_2, &y_2, &v);
				for (int i = x_1; i <= x_2; i++) add(y_1, y_2, v, 1, c, 1, i);
			}
			if (mes == 2) {
				scanf("%d %d %d %d %lld", &x_1, &y_1, &x_2, &y_2, &v);
				for (int i = x_1; i <= x_2; i++) set(y_1, y_2, v, 1, c, 1, i);
			}
			if (mes == 3) {
				scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
				ll sm = 0, mn = INF, mx = -INF;
				for (int i = x_1; i <= x_2; i++) {
					sm += query_sum(y_1, y_2, 1, c , 1, i);
					mn = min(mn, query_min(y_1, y_2, 1, c, 1, i));
					mx = max(mx, query_max(y_1, y_2, 1, c, 1, i));
				}
				printf("%lld %lld %lld\n", sm, mn, mx);
			}
		}
	}
	return 0;
}
