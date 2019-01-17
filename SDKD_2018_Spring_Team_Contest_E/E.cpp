//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月06日 星期五 18时35分05秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1e4 + 5, MOD = 1e9 + 7;

int t;
int ans[MAXN][6];

int main()
{
	for (int i = 0; i <= 5; i++) ans[0][i] = 0;
	for (int j = 0; j <= 5; j++)
		for (int i = 1; i <= 10000; i++) {
			long long add = 1;
			for (int k = 1; k <= j; k++) add = add * i % MOD;
			ans[i][j] = ((long long)ans[i - 1][j] + add) % MOD;
		}
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", ans[n][k]);
	}
	return 0;
}
