//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月19日 星期日 13时20分03秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n;
int a[MAXN], visited[MAXN];
ll c[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = ++cnt;
		int x = i;
		while (!visited[a[x]]) {
			x = a[x];
			visited[x] = cnt;
		}
		if (visited[a[x]] == cnt) {
			int ed = x;
			ll now = c[x];
			x = a[x];
			while (x != ed) now = min(now, c[x]), x = a[x];
			ans += now;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
