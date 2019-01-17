//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 18时16分12秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int n;
int b[MAXN];

int find(int ans)
{
	int d = b[2] - b[1], now = b[2];
	for (int i = 3; i <= n; i++) {
		now += d;
		if (now < b[i] - 1 || b[i] + 1 < now) {
			ans = INF;
			break;
		}
		if (b[i] - 1 == now || now == b[i] + 1) ans++;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	if (n <= 2)
		printf("0\n");
	else {
		int x = b[1], y = b[2];
		int ans = INF;
		ans = min(ans, find(0));
		b[1] = x + 1; b[2] = y + 1;
		ans = min(ans, find(2));
		b[1] = x; b[2] = y + 1;
		ans = min(ans, find(1));
		b[1] = x - 1; b[2] = y + 1;
		ans = min(ans, find(2));
		b[1] = x - 1; b[2] = y;
		ans = min(ans, find(1));
		b[1] = x - 1; b[2] = y - 1;
		ans = min(ans, find(2));
		b[1] = x + 1; b[2] = y;
		ans = min(ans, find(1));
		b[1] = x + 1; b[2] = y - 1;
		ans = min(ans, find(2));
		b[1] = x; b[2] = y - 1;
		ans = min(ans, find(1));
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}
