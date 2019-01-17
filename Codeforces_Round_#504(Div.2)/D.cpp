//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月17日 星期五 23时49分04秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct segment {
	int l, r, min, max, mark;
};

int n, q;
vector<int> pos[MAXN];
int l[MAXN], r[MAXN], a[MAXN], ans[MAXN];
segment tree[MAXN << 2];

void update(int rt)
{
	tree[rt].min = min(tree[rt << 1].min, tree[rt << 1 | 1].min);
	tree[rt].max = max(tree[rt << 1].max, tree[rt << 1 | 1].max);
}

void push_down(int rt)
{
	if (tree[rt].mark) {
		tree[rt << 1].mark = tree[rt].mark;
		tree[rt << 1 | 1].mark = tree[rt].mark;
		tree[rt << 1].min = tree[rt << 1].max = tree[rt].mark;
		tree[rt << 1 | 1].min = tree[rt << 1 | 1].max = tree[rt].mark;
		tree[rt].mark = 0;
	}
}

void build(int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].mark = 0;
	if (l == r) {
		tree[rt].min = tree[rt].max = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	update(rt);
}

void modify(int l, int r, int num, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) {
		tree[rt].min = tree[rt].max = num;
		tree[rt].mark = num;
		return;
	}
	push_down(rt);
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (l <= mid) modify(l, r, num, rt << 1);
	if (r >= mid + 1) modify(l, r, num, rt << 1 | 1);
	update(rt);
}

int query_min(int l, int r, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].min;
	push_down(rt);
	int ans = INF;
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (l <= mid) ans = min(ans, query_min(l, r, rt << 1));
	if (r >= mid + 1) ans = min(ans, query_min(l, r, rt << 1 | 1));
	return ans;
}

int query_max(int l, int r, int rt)
{
	if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].max;
	push_down(rt);
	int ans = 0;
	int mid = (tree[rt].l + tree[rt].r) >> 1;
	if (l <= mid) ans = max(ans, query_max(l, r, rt << 1));
	if (r >= mid + 1) ans = max(ans, query_max(l, r, rt << 1 | 1));
	return ans;
}

int main()
{
	scanf("%d %d", &n, &q);
	int last = 0;
	bool havelast = false;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == q) havelast = true;
		if (a[i] == 0) last = i;
		pos[a[i]].push_back(i);
	}
	memset(l, 0, sizeof(l));
	for (int i = 1; i <= n; i++) {
		if (l[a[i]] == 0) l[a[i]] = i;
		r[a[i]] = i;
	}
	build(1, n, 1);
	bool flag = true;
	for (int i = 1; i <= q && flag; i++) {
		if (l[i] == 0) continue;
		int mn = query_min(l[i], r[i], 1), mx = query_max(l[i], r[i], 1);
		if (mn != INF && mx != 0 && mn != mx) flag = false;
		for (int j = 0; j < (int)pos[i].size(); j++) modify(pos[i][j], pos[i][j], i, 1);
	}
	if (!flag || (last == 0 && !havelast))
		printf("NO\n");
	else {
		printf("YES\n");
		if (!havelast) a[last] = q;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				if (i == 1) {
					for (int j = 2; j <= n; j++)
						if (a[j] != 0)  {
							ans[i] = a[j];
							break;
						}
				}
				else
					ans[i] = ans[i - 1];
			}
			else
				ans[i] = a[i];
		}
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	}
	return 0;
}
