//******************************************************************************
// File Name: POJ_1180.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月10日 星期五 15时34分52秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 10005;

int n, s, head, tail;
int dq[MAXN];
ll sum_t[MAXN], sum_f[MAXN], dp[MAXN];

ll get_up(int k, int p)
{
	return dp[k] - dp[p];
}

ll get_down(int k, int p)
{
	return sum_t[k] - sum_t[p];
}

bool judge(int i, int j, int k)
{
	ll x1 = get_down(i, j), x2 = get_down(j, k);
	ll y1 = get_up(i, j), y2 = get_up(j, k);
	return x1 * y2 - y1 * x2 <= 0;
}

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld", &sum_t[i], &sum_f[i]);
	for (int i = n - 1; i >= 1; i--)
		sum_t[i] += sum_t[i + 1], sum_f[i] += sum_f[i + 1];
	dp[n + 1] = 0;
	head = tail = 0;
	dq[tail++] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (tail - head >= 2 && get_up(dq[head], dq[head + 1]) >= sum_f[i] * get_down(dq[head], dq[head + 1])) head++;
		int k = dq[head];
		dp[i] = dp[k] + (sum_t[i] - sum_t[k] + s) * sum_f[i];
		while (tail - head >= 2 && judge(dq[tail - 2], dq[tail - 1], i)) tail--;
		dq[tail++] = i;
	}
	printf("%lld\n", dp[1]);
	return 0;
}
