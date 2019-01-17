//******************************************************************************
// File Name: HDU_2588.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月28日 星期六 20时52分20秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int t, n, m;

int phi(int x)
{
	int ans = x;
	for (int i = 2; (ll)i * i <= x; i++) {
		if (x % i == 0) {
			ans /= i; ans *= (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans /= x, ans *= (x - 1);
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		int ans = 0;
		for (int i = 1; (ll)i * i <= n; i++) {
			if (n % i == 0) {
				int b = n / i;
				if (i >= m) ans += phi(b);
				if (i != b && b >= m) ans += phi(i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
