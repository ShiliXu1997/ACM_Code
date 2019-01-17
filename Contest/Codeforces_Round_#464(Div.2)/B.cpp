//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月02日 星期一 21时15分26秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

long long n;
int k;

int main()
{
	scanf("%lld %d", &n, &k);
	long long ans = 0;
	long long t = 1, num = 0;
	for (int i = 1; i <= k; i++) {
		long long x;
		scanf("%lld", &x);
		if (n / x * x > ans) {
			ans = n / x * x;
			t = i;
			num = n / x;
		}
	}
	printf("%lld %lld", t, num);
	return 0;
}
