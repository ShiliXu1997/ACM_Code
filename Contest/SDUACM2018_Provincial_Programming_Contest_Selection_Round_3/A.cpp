//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月29日 星期四 20时54分10秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5, BASE = 1e6;
const long long INF = 0x3fffff3f3f3f3f3f, DAY = (long long)12 * 1e12;

int n;
long long t[MAXN], sum[MAXN];

long long min(long long a, long long b)
{
	return (a < b ? a : b);
}

int main()
{
	scanf("%d", &n);
	long long h, m, s;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &h, &m, &s);
		t[i] = h * BASE * BASE + m * BASE + s;
	}
	sort(t + 1, t + 1 + n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + t[i];
	long long ans = INF;
	for (int i = 1; i <= n; i++) {
		long long now = (long long)(n - 1) * t[i] - sum[i - 1] + (long long)(n - i) * DAY - sum[n] + sum[i];
		ans = min(ans, now);
	}
	long long hh = ans / (long long)(1e12), mm = ans / (long long)(1e6) % (long long)1e6, ss = ans - hh * (long long)1e12 - mm * (long long)1e6;
	printf("%lld %lld %lld\n", hh, mm, ss);
	return 0;
}
