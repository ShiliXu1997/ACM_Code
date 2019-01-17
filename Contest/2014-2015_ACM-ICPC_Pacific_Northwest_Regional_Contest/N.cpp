//************************************************************************
// File Name: N.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月15日 星期日 13时05分32秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int t;
int cnt[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		int n, mx = 0;
		cnt[0] = 0;
		scanf("%d", &n);
		while (n--) {
			int x;
			scanf("%d", &x);
			cnt[x]++;
			if (cnt[x] > cnt[mx] || cnt[x] == cnt[mx] && x < mx) mx = x;
		}
		printf("%d\n", mx);
	}
	return 0;
}
