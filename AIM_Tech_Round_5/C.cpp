//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月29日 星期三 11时16分15秒
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

const int MAXN = 2e5, INF = 0x3f3f3f3f;

struct rec {
	int x1, y1, x2, y2;

	rec() {}
	rec(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int n;
rec r[MAXN], pre[MAXN], suf[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d %d %d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2);
	pre[0] = suf[n + 1] = rec(-INF, -INF, INF, INF);
	for (int i = 1; i <= n; i++) {
		pre[i].x1 = max(pre[i - 1].x1, r[i].x1);
		pre[i].y1 = max(pre[i - 1].y1, r[i].y1);
		pre[i].x2 = min(pre[i - 1].x2, r[i].x2);
		pre[i].y2 = min(pre[i - 1].y2, r[i].y2);
	}
	for (int i = n; i >= 1; i--) {
		suf[i].x1 = max(suf[i + 1].x1, r[i].x1);
		suf[i].y1 = max(suf[i + 1].y1, r[i].y1);
		suf[i].x2 = min(suf[i + 1].x2, r[i].x2);
		suf[i].y2 = min(suf[i + 1].y2, r[i].y2);
	}
	bool flag = false;
	rec now;
	for (int i = 1; i <= n && !flag; i++) {
		now.x1 = max(pre[i - 1].x1, suf[i + 1].x1);
		now.y1 = max(pre[i - 1].y1, suf[i + 1].y1);
		now.x2 = min(pre[i - 1].x2, suf[i + 1].x2);
		now.y2 = min(pre[i - 1].y2, suf[i + 1].y2);
		if (now.x1 <= now.x2 && now.y1 <= now.y2) flag = true;
	}
	printf("%d %d\n", now.x1, now.y1);
	return 0;
}
