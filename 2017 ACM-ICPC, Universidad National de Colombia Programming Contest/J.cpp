//************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月21日 星期六 14时27分35秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 3e7;

int n, m, q;
int a[MAXN + 5], cnt[MAXN + 5];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (int i = m + 1; i <= n; i++) a[i] = (a[i - m] + a[i - m + 1]) % MAXN;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) cnt[a[i]]++;
	int index = 0;
	for (int i = 0; i < MAXN; i++) {
		while (cnt[i]) {
			a[++index] = i;
			cnt[i]--;
		}
	}
	while (q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", a[x]);
	}
	return 0;
}
