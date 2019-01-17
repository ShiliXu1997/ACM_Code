//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月30日 星期一 22时46分25秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, k;

int main()
{
	scanf("%lld %lld %lld", &n, &m, &k);
	if (k <= n - 1) {
		printf("%lld 1", 1 + k);
		return 0;
	}
	k -= (n - 1);
	ll p = k / ((ll)2 * (m - 1)) * 2, q = k % ((ll)2 * (m - 1));
	if (q == 0) {
		printf("%lld 2", n - p + 1);
	}
	else
	if (q <= m - 1) {
		printf("%lld %lld", n - p, q + 1);
	}
	else
	if (q < (m - 1) * 2) {
		printf("%lld %lld", n - p - 1, m - (q - m + 1) + 1);
	}
	return 0;
}
