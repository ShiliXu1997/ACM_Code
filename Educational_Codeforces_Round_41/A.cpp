//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 22时09分51秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005, INF = 0x3f3f3f3f;

int n, m;
int cnt[MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	while (m--) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int mn = INF;
	for (int i = 1; i <= n; i++) mn = min(mn, cnt[i]);
	printf("%d\n", mn);
	return 0;
}
