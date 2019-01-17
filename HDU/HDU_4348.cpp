//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月13日 星期二 13时22分53秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct segment {
	long long sum, mark;
	int lson, rson;
};

int n, m, cnt, time;
int a[MAXN], root[MAXN];
segment seg[MAXN * 30];

void build(int left, int right, int &rt)
{
	rt = ++cnt;
	seg[rt].mark = 0;
	int mid = (left + right) >> 1;
	if (left == right) {
		seg[rt].sum = (long long)a[mid];
		return;
	}
	build(left, mid, seg[rt].lson);
	build(mid + 1, right, seg[rt].rson);
	seg[rt].sum = seg[seg[rt].lson].sum + seg[seg[rt].rson].sum;
}

void modify(int l, int r, long long num, int left, int right, int pre, int &now)
{
	now = ++cnt;
	seg[now] = seg[pre];
	if (l <= left && right <= r) {
		seg[now].sum += num * (right - left + 1);
		seg[now].mark += num;
		return;
	}
	int mid = (left + right) >> 1;
	if (l <= mid) {
		seg[now].sum += num * (min(r, mid) - max(l, left) + 1);
		modify(l, r, num, left, mid, seg[pre].lson, seg[now].lson);
	}
	if (r >= mid + 1) {
		seg[now].sum += num * (min(r, right) - max(l, mid + 1) + 1);
		modify(l, r, num, mid + 1, right, seg[pre].rson, seg[now].rson);
	}
}

long long query(int l, int r, int left, int right, int rt)
{
	if (l <= left && right <= r) return seg[rt].sum;
	int mid = (left + right) >> 1;
	long long ans = 0;
	if (left <= l && r <= right) ans += seg[rt].mark * (r - l + 1);
	else
	if (l <= left && r <= right) ans += seg[rt].mark * (r - left + 1);
	else
	if (left <= l && right <= r) ans += seg[rt].mark * (right - l + 1);
	if (l <= mid) ans += query(l, r, left, mid, seg[rt].lson);
	if (r >= mid + 1) ans += query(l, r, mid + 1, right, seg[rt].rson);
	return ans;
}

int main()
{
	bool flag = false;
	while (scanf("%d %d", &n, &m) == 2) {
		if (flag)
			printf("\n");
		else
			flag = true;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		cnt = 0; time = 0;
		build(1, n, root[0]);
		while (m--) {
			char mes[2];
			scanf("%s", mes);
			if (mes[0] == 'C') {
				int l, r;
				long long d;
				scanf("%d %d %lld", &l, &r, &d);
				time++;
				modify(l, r, d, 1, n, root[time - 1], root[time]);
			}
			if (mes[0] == 'Q') {
				int l, r;
				scanf("%d %d", &l, &r);
				printf("%lld\n", query(l, r, 1, n, root[time]));
			}
			if (mes[0] == 'H') {
				int l, r, t;
				scanf("%d %d %d", &l, &r, &t);
				printf("%lld\n", query(l, r, 1, n, root[t]));
			}
			if (mes[0] == 'B') {
				int t;
				scanf("%d", &t);
				if (t < time) {
					cnt = root[t + 1] - 1;
					time = t;
				}
			}
		}
	}
	return 0;
}

