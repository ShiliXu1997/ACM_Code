//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 22时11分54秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 15;

ll a[MAXN], ans[MAXN];

int main()
{
	for (int i = 1; i <= 14; i++) scanf("%lld", &a[i]);
	ll sum = 0;
	for (int i = 1; i <= 14; i++)
		if (a[i]) {
			memset(ans, 0, sizeof(ans));
			ll now = a[i];
			if (14 - i <= now) {
				for (int j = i + 1; j <= 14; j++) ans[j]++;
				now -= (14 - i);
				for (int j = 1; j <= 14; j++) ans[j] += now / 14;
				for (int j = 1; j <= now % 14; j++) ans[j]++;
			}
			else {
				for (int j = i + 1; j <= i + now; j++) ans[j]++;
			}
			for (int j = 1; j <= 14; j++) {
				if (j == i) continue;
				ans[j] += a[j];
			}
			ll cnt = 0;
			for (int j = 1; j <= 14; j++)
				if (ans[j] % 2 == 0) cnt += ans[j];
			sum = max(sum, cnt);
		}
	printf("%lld", sum);
	return 0;
}
