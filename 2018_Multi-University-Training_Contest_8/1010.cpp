//******************************************************************************
// File Name: 1010.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月20日 星期一 21时17分21秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, n, m;
int h[MAXN], mx[MAXN << 2], vl[MAXN << 2], l[MAXN << 2], r[MAXN << 2];

int calc(int v, int rt)
{
	if (l[rt] == r[rt]) return (v < mx[rt]);
	if (mx[rt << 1] <= v)
		return calc(v, rt << 1 | 1);
	else
		return calc(v, rt << 1) + (vl[rt] - vl[rt << 1]);
}

void update(int rt)
{
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	vl[rt] = vl[rt << 1] + calc(mx[rt << 1], rt << 1 | 1);
}

void build(int left, int right, int rt)
{
	l[rt] = left, r[rt] = right;
	if (left == right) {
		mx[rt] = h[left];
		vl[rt] = 1;
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, rt << 1);
	build(mid + 1, right, rt << 1 | 1);
	update(rt);
}

void modify(int pos, int num, int rt)
{
	if (l[rt] == r[rt]) {
		mx[rt] = num;
		return;
	}
	int mid = (l[rt] + r[rt]) >> 1;
	if (pos <= mid) modify(pos, num, rt << 1);
	if (pos >= mid + 1) modify(pos, num, rt << 1 | 1);
	update(rt);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
		build(1, n, 1);
		while (m--) {
			int x, y;
			scanf("%d %d", &x, &y);
			modify(x, y, 1);
			printf("%d\n", vl[1]);
			modify(x, h[x], 1);
		}
	}
	return 0;
}
