//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月03日 星期二 21时56分38秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 5;

int q, cnt;
long long sum[MAXN];

double calc(int m)
{
	long long x = sum[cnt] - sum[cnt - 1];
	return (double)(x + sum[m]) / (m + 1);
}

int main()
{
	scanf("%d", &q);
	int mes;
	long long x;
	cnt = 0;
	sum[0] = 0;
	while (q--) {
		scanf("%d", &mes);
		if (mes == 1) {
			scanf("%lld", &x);
			sum[cnt + 1] = sum[cnt] + x;
			cnt++;
		}
		else {
			int l = 1, r = cnt;
			while (l + 1 < r) {
				int lmid = (l + r) >> 1, rmid = (lmid + r) >> 1;
				if (calc(lmid) > calc(rmid))
					l = lmid;
				else
					r = rmid;
			}
			double ans = 1e17;
			for (int i = l; i <= r; i++) ans = min(ans, calc(i));
			printf("%.8f\n", sum[cnt] - sum[cnt - 1] - ans);
		}
	}
	return 0;
}
