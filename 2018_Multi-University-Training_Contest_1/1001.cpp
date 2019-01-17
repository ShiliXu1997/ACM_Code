//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月24日 星期二 14时12分19秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

int t, n;
ll ans[MAXN];

void init()
{
	for (int paigu = 0; paigu < 83334; paigu++) {
		for (int i = 1; i <= 12; i++) {
			int now = paigu * 12 + i;
			if (now % 3 == 0)
				ans[now] = (ll)(now / 3) * (now / 3) * (now / 3);
			else
			if (i <= 2 || i == 5 || i == 7 || i == 10 || i == 11)
				ans[now] = -1;
			else {
				int fen = now / 4;
				ans[now] = (ll)fen * fen * (2 * fen);
			}
		}
	}
}

int main()
{
	init();
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}
