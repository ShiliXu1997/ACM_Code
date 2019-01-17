//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月08日 星期日 00时20分58秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1005;

struct num {
	long long a, b, ans;

	bool operator<(const num &another) const
	{
		return ans > another.ans;
	}
};

int n, k1, k2;
num p[MAXN];

int main()
{
	scanf("%d %d %d", &n, &k1, &k2);
	for (int i = 1; i <= n; i++) scanf("%lld", &p[i].a);
	for (int i = 1; i <= n; i++) scanf("%lld", &p[i].b);
	for (int i = 1; i <= n; i++) p[i].ans = abs(p[i].a - p[i].b);
	for (int i = 1; i <= k1; i++) {
		sort(p + 1, p + 1 + n);
		p[1].ans = abs(p[1].ans - 1);
	}
	for (int i = 1; i <= k2; i++) {
		sort(p + 1, p + 1 + n);
		p[1].ans = abs(p[1].ans - 1);	
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++) sum += p[i].ans * p[i].ans;
	printf("%lld", sum);
	return 0;
}
