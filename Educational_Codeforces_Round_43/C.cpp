//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 01时06分34秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

struct segment {
	int left, right, id;
};

int n;
segment seg[MAXN];

bool cmp_1(const segment &a, const segment &b)
{
	if (a.left == b.left) return a.right < b.right;
	return a.left < b.left;
}

bool cmp_2(const segment &a, const segment &b)
{
	if (a.right == b.right) return a.left < b.left;
	return a.right < b.right;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &seg[i].left, &seg[i].right), seg[i].id = i;
	bool flag = false;
	int mx = 0, mn = INF, mxw, mnw;
	sort(seg + 1, seg + 1 + n, cmp_1);
	for (int i = n; i >= 1 && !flag; i--) {
		if (mn <= seg[i].right) {
			printf("%d %d", mnw, seg[i].id);
			flag = true;
		}
		if (seg[i].right < mn) {
			mn = seg[i].right;
			mnw = seg[i].id;
		}
	}
	if  (flag) return 0;
	sort(seg + 1, seg + 1 + n, cmp_2);
	for (int i = 1; i <= n && !flag; i++) {
		if (mx >= seg[i].left) {
			printf("%d %d", mxw, seg[i].id);
			flag = true;
		}
		if (seg[i].left > mx) {
			mx = seg[i].left;
			mxw = seg[i].id;
		}
	}
	if (!flag) printf("-1 -1");
	return 0;
}
