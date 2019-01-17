//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月22日 星期日 00时02分31秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 6;

int t;
int cnt[MAXN], tot[MAXN];

bool check(int n, int m, int x, int y)
{
	memset(tot, 0, sizeof(tot));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int dist = abs(i - x) + abs(j - y);
			tot[dist]++;
			if (tot[dist] > cnt[dist]) return false;
		}
	return true;
}

int main()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &t);
	int mn, mx = 0;
	for (int i = 1; i <= t; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		mx = max(mx, x);
	}
	for (int i = 1; i <= mx; i++)
		if (cnt[i] % 4 != 0) {
			mn = i;
			break;
		}
	for (int n = 1; n <= t; n++) {
		if (t % n != 0) continue;
		int m = t / n, x = mn, y = n - x + m - mx;
		if (check(n, m, x, y)) {
			printf("%d %d\n", n, m);
			printf("%d %d\n", x, y);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
