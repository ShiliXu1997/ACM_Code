//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 16时12分36秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 5005, MAXM = 1e6 + 5;

int t, n, cnt;
int a[MAXN], sb[MAXM];

int main()
{
	freopen("cases.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) sb[a[j]] = 0;
			int cnt = 0;
			for (int j = i; j <= n; j++) {
				sb[a[j]]++;
				if (sb[a[j]] & 1)
					cnt++;
				else
					cnt--;
				if (cnt == 1) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
