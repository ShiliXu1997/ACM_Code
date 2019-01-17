//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月12日 星期一 13时18分03秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

struct segment {
	int data, lson, rson;
};

int t, n, m, cnt;
int a[MAXN], b[MAXN], root[MAXN];
segment seg[MAXN * 20];

void build(int left, int right, int &rt)
{
	rt = ++cnt;
	int mid = (left + right) >> 1;
	seg[rt].data = 0;
	if (left == right) return;
	build(left, mid, seg[rt].lson);
	build(mid + 1, right, seg[rt].rson);
}

void modify(int left, int right, int pos, int num, int pre, int &now)
{
	now = ++cnt;
	seg[now] = seg[pre];
	if (left == right) {
		seg[now].data += num;
		return;
	}
	int mid = (left + right) >> 1;
	if (pos <= mid)
		modify(left, mid, pos, num, seg[pre].lson, seg[now].lson);
	else
		modify(mid + 1, right, pos, num, seg[pre].rson, seg[now].rson);
	seg[now].data = seg[seg[now].lson].data + seg[seg[now].rson].data;
}

int query(int left, int right, int x, int y, int k)
{
	int mid = (left + right) >> 1;
	if (left == right) return b[mid];
	int cnt = seg[seg[y].lson].data - seg[seg[x].lson].data;
	if (k <= cnt)
		return query(left, mid, seg[x].lson, seg[y].lson, k);
	else
		return query(mid + 1, right, seg[x].rson, seg[y].rson, k - cnt);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		cnt = 0;
		build(1, n, root[0]);
		for (int i = 1; i <= n; i++) {
			int id = lower_bound(b + 1, b + 1 + n, a[i]) - b;
			modify(1, n, id, 1, root[i - 1], root[i]);
		}
		while (m--) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", query(1, n, root[l - 1], root[r], k));
		}
	}
	return 0;
}

