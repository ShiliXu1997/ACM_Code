//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月07日 星期一 02时22分49秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n;
map<int, int> dp, pos;
int last[MAXN];

void show(int now)
{
	if (last[now]) show(last[now]);
	printf("%d ", now);
}

int main()
{
	scanf("%d", &n);
	int ans, mx = 0;
	memset(last, 0, sizeof(last));
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pos[x] = i;
		if (!dp.count(x - 1))
			dp[x] = 1;
		else {
			dp[x] = dp[x - 1] + 1;
			last[i] = pos[x - 1];
		}
		if (dp[x] > mx) {
			ans = x;
			mx = dp[x];
		}
	}
	printf("%d\n", mx);
	show(pos[ans]);
	return 0;
}
