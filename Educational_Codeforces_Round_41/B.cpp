//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 22时17分41秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k;
int a[MAXN], sum[MAXN], nor[MAXN];

int main()
{
	scanf("%d %d", &n, &k);
	sum[0] = nor[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		if (t)
			nor[i] = nor[i - 1] + a[i];
		else
			nor[i] = nor[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n - k + 1; i++)
		ans = max(ans, sum[i + k - 1] - sum[i - 1] + nor[i - 1] + nor[n] - nor[i + k - 1]);
	printf("%d", ans);
	return 0;
}
