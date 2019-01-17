//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月28日 星期六 16时06分52秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int t, n, a;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &a);
		int ans;
		if (n & 1) {
			int half = (n - 1) / 2;
			if (half <= a - 1)
				ans = half * 2 + 1;
			else
				ans = (a - 1) * 2 + 1;
		}
		else {
			int half = n / 2;
			if (half <= a - 1)
				ans = half * 2;
			else
				ans = (a - 1) * 2;
			if (ans < n) ans += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
