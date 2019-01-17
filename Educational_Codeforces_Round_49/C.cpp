//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月18日 星期六 23时19分52秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5, MAXM = 1e4 + 5;
const double EPS = 1e-8;

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

int t, n, cnt;
int a[MAXM], len[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			a[x]++;
			if (a[x] == 1) len[++cnt] = x;
		}
		bool flag = false;
		int x, y;
		for (int i = 1; i <= cnt && !flag; i++) {
			if (a[len[i]] >= 4) {
				x = y = len[i];
				printf("%d %d %d %d\n", x, x, y, y);
				flag = true;
			}
		}
		if (flag) continue;
		sort(len + 1, len + 1 + cnt);
		double ans = 1e17;
		int l, r;
		for (l = 1; l <= cnt; l++) if (a[len[l]] >= 2) break;
		while (true) {
			for (r = l + 1; r <= cnt; r++) {
				if (a[len[r]] >= 2) {
					double now = 4.0 + (double)(len[l] * len[l] + len[r] * len[r]) / (double)(len[l] * len[r]) * 2.0;
					if (now < ans) {
						ans = now;
						x = len[l], y = len[r];
					}
					l = r;
					break;
				}
			}
			if (r > cnt) break;
		}
		printf("%d %d %d %d\n", x, x, y, y);
	}
	return 0;
}
