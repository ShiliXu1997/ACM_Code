//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 01时24分57秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

unsigned long long n;

int main()
{
	scanf("%llu", &n);
	unsigned long long ans = 0, cnt = n - 1, now = 1;
	while (cnt) ans += (cnt + 1) / 2 * now, now <<= 1, cnt -= (cnt + 1) / 2;
	printf("%llu", ans);
	return 0;
}
