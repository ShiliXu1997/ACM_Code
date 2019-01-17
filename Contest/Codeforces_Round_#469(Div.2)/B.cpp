//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月09日 星期五 16时20分16秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
long long a[MAXN], b[MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	int i = 1, j = 1, ans = 0;
	long long sum_1 = 0, sum_2 = 0;
	while (i <= n && j <= m) {
		if (sum_1 < sum_2) sum_1 += a[i++];
		else
		if (sum_1 > sum_2) sum_2 += b[j++];
		else
		if (sum_1 == 0) {
			sum_1 += a[i++];
			sum_2 += b[j++];
		}
		if (sum_1 == sum_2) {
			ans++;
			sum_1 = sum_2 = 0;
		}
	}
	if (i == n + 1 && j != m + 1 || i != n + 1 && j == m + 1) ans++;
	printf("%d", ans);
	return 0;
}
