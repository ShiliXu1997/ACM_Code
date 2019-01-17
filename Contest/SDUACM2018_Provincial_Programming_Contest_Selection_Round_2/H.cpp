//************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 14时29分28秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct num {
	int dig[21];

	num(int x)
	{
		for (int i = 1; i <= 20; i++) dig[i] = (x >> (i - 1)) & 1;
	}

	bool operator<(const num &another) const
	{
		for (int i = 20; i >= 1; i--) {
			if (dig[i] >= 1 && another.dig[i] >= 1)
				continue;
			else
			if (dig[i] == 0 && another.dig[i] == 0)
				continue;
			else
				return  dig[i] < another.dig[i];
		}
		return false;
	}
	
	bool operator==(const num &another) const
	{
		for (int i = 1; i <= 20; i++)
			if (dig[i] == 0 && another.dig[i] > 0 || dig[i] > 0 && another.dig[i] == 0)
				return false;
		return true;
	}
};

int t, n, k;
int a[MAXN];

int main()
{
	freopen("wifi.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		num stand(k);
		num now(0);
		int ans = 0, l = 0, r = 0;
		while (true) {
			r++;
			if (r > n) {
				ans = max(ans, r - l - 1);
				break;
			}
			num p(a[r]);
			for (int i = 1; i <= 20; i++) now.dig[i] += p.dig[i];
			if (stand < now) {
				ans = max(ans, r - l - 1);
				while (stand < now && l < r) {
					l++;
					num pp(a[l]);
					for (int i = 1; i <= 20; i++) now.dig[i] -= pp.dig[i];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
