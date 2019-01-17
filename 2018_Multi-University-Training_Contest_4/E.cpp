//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月01日 星期三 14时59分40秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 150;

int t, n, m;
int grid[MAXN][MAXN], dp[MAXN][MAXN];
int a[MAXN];

void gen(int sz)
{
	int cur = 0;
	for (int i = 0; i <= sz; i++) {
		for (int j = 0; j <= i; j++) {
			grid[j][i - j] = a[cur];
			cur = (cur + 1) % n;
		}
	}
}

void init()
{
	int T = 2 * n;
	for (int i = 0; i <= T; i++) dp[i][0] = dp[0][i] = 0;
	for (int i = 1; i <= T; i++)
		for (int j = 1; j <= T; j++)
			dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
}

ll sum(int x, int y)
{
	if (x < 0 || y < 0) return 0;
	x++, y++;
	int T = 2 * n;
	ll ans = 0, r = x / T, c = y / T;
	int rm = x % T, cm = y % T;
	ans += r * c * dp[T][T];
	ans += c * dp[rm][T] + r * dp[T][cm];
	ans += dp[rm][cm];
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		gen(4 * n);
		init();
		scanf("%d", &m);
		while (m--) {
			int x0, x1, y0, y1;
			scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
			printf("%lld\n", sum(x1, y1) + sum(x0 - 1, y0 - 1) - sum(x1, y0 - 1) - sum(x0 - 1, y1));
		}
	}
	return 0;
}
