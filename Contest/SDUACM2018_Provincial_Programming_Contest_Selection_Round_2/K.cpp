//************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 13时35分24秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
long long n, k;

int main()
{
	freopen("chess.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &k);
		long long ans = (n / (k + 1)) * (n / (k + 1)) * (k + 1);
		ans += n % (k + 1) * 2 * (n / (k + 1)) + n % (k + 1);
		printf("%lld\n", n * n - ans);
	}
	return 0;
}
