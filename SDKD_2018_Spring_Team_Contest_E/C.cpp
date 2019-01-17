//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月06日 星期五 18时20分59秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int t, n;
int a[MAXN], prenum[MAXN], sufnum[MAXN];

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			if (i == 1) prenum[i] = a[i];
			prenum[i] = gcd(prenum[i - 1], a[i]);
		}
		for (int i = n; i >= 1; i--) {
			if (i == n) sufnum[i] = a[i];
			sufnum[i] = gcd(sufnum[i + 1], a[i]);
		}
		int ans = max(sufnum[2], prenum[n - 1]);
		for (int i = 2; i <= n - 1; i++)
			ans = max(ans, gcd(prenum[i - 1], sufnum[i + 1]));
		printf("%d\n", ans);
	}
	return 0;
}
