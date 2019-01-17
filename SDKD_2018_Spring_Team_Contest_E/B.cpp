//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月06日 星期五 16时57分11秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 3005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct room {
	long long x, cost;

	bool operator<(const room &another) const
	{
		return x < another.x;
	}
};

int n;
room rm[MAXN];
long long dp[MAXN][2];

int main()
{
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) scanf("%lld %lld", &rm[i].x, &rm[i].cost);
		sort(rm + 1, rm + 1 + n);
		dp[1][1] = rm[1].cost;
		dp[1][0] = INF;
		for (int i = 2; i <= n; i++) {
			dp[i][1] = min(dp[i - 1][0] + rm[i].cost, dp[i - 1][1] + rm[i].cost);
			dp[i][0] = INF;
			long long dist = 0;
			for (int j = i - 1; j >= 1; j--) {
				dist += (i - j) * (rm[j + 1].x - rm[j].x);
				dp[i][0] = min(dp[i][0], dp[j][1] + dist);
			}
		}
		printf("%lld\n", min(dp[n][0], dp[n][1]));
	}
	return 0;
}
