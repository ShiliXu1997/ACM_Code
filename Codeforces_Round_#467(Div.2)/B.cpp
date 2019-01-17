//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月26日 星期一 00时12分21秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;

long long p, y, cnt;
long long prime[MAXN + 5];
bool boolprime[MAXN + 5];

void euler()
{
	cnt = 0;
	memset(boolprime, false, sizeof(boolprime));
	for (int i = 2; i <= MAXN; i++) {
		if (!boolprime[i]) prime[++cnt] = (long long)i;
		for (int j = 1; j <= cnt && prime[j] * i <= MAXN; j++) {
			boolprime[(int)prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	scanf("%lld %lld", &p, &y);
	euler();
	if (y % 2 == 0) y--;
	long long ans = -1;
	while (y > p) {
		bool flag = true;
		for (int i = 1; i <= cnt && prime[i] <= p &&prime[i] * prime[i] <= y && flag; i++)
			if (y % prime[i] == 0) flag = false;
		if (flag) {
			ans = y;
			break;
		}
		y -= 2;
	}
	printf("%lld", ans);
	return 0;
}

