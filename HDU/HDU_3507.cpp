//******************************************************************************
// File Name: HDU_3507.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月05日 星期日 20时46分42秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

int n, m, head, tail;
int dq[MAXN];
ll sum[MAXN], dp[MAXN];

ll get_up(int i, int j)
{
	return (dp[i] + sum[i] * sum[i]) - (dp[j] + sum[j] * sum[j]);
}

ll get_down(int i, int j)
{
	return (ll)2 * (sum[i] - sum[j]);
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		sum[0] = dp[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &sum[i]), sum[i] += sum[i - 1];
		head = tail = 0;
		dq[tail++] = 0;
		for (int i = 1; i <= n; i++) {
			while (tail - head >= 2 && get_up(dq[head + 1], dq[head]) <= sum[i] * get_down(dq[head + 1], dq[head])) head++;	
			dp[i] = dp[dq[head]] + (sum[i] - sum[dq[head]]) * (sum[i] - sum[dq[head]]) + m;
			while (tail - head >= 2 && get_up(dq[tail - 1], dq[tail - 2]) * get_down(i, dq[tail - 1]) >= get_up(i, dq[tail - 1]) * get_down(dq[tail - 1], dq[tail - 2])) tail--;
			dq[tail++] = i;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}
