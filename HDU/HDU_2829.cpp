//******************************************************************************
// File Name: HDU_2829.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月10日 星期五 10时43分32秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int n, m;
ll sum[MAXN], w[MAXN];
int head[MAXN], tail[MAXN];
ll dq[MAXN][MAXN], dp[MAXN][MAXN];

ll get_up(int j, int k, int p)
{
	return (dp[k][j] - w[k] + sum[k] * sum[k]) - (dp[p][j] - w[p] + sum[p] * sum[p]);
}

ll get_down(int k, int p)
{
	return (sum[k] - sum[p]);
}

bool judge(int j, int i)
{
	ll x1 = get_down(dq[j][tail[j] - 1], dq[j][tail[j] - 2]);
	ll y1 = get_up(j, dq[j][tail[j] - 1], dq[j][tail[j] - 2]);
	ll x2 = get_down(i, dq[j][tail[j] - 1]);
	ll y2 = get_up(j, i, dq[j][tail[j] - 1]);
	return (x1 * y2 - y1 * x2) < 0;
}

bool check(int j, int i)
{
	return (get_up(j, dq[j][head[j]], dq[j][head[j] + 1]) >= sum[i] * get_down(dq[j][head[j]], dq[j][head[j] + 1]));
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2 && (n | m)) {
		sum[0] = w[1] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &sum[i]);
			sum[i] += sum[i - 1];
			w[i] = w[i - 1] + sum[i - 1] * (sum[i] - sum[i - 1]);
		}
		for (int j = 0; j <= m; j++) {
			head[j] = tail[j] = 0;
			for (int i = j + 1; i <= n; i++) {
				if (j == 0)
					dp[i][j] = w[i];
				else {
					while (tail[j - 1] - head[j - 1] >= 2 && check(j - 1, i)) head[j - 1]++;
					int k = dq[j - 1][head[j - 1]];
					dp[i][j] = dp[k][j - 1] + w[i] - w[k] - sum[k] * sum[i] + sum[k] * sum[k];
				}
				while (tail[j] - head[j] >= 2 && judge(j, i)) tail[j]--;
				dq[j][tail[j]++] = i;
			}
		}
		printf("%lld\n", dp[n][m]);
	}
	return 0;
}
