//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月17日 星期二 22时20分46秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 5e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, t;
ll a, b, c;
int rec[MAXN];

int main()
{
	scanf("%d %lld %lld %lld %d", &n, &a, &b, &c, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &rec[i]);
	if (c <= b)
		printf("%lld\n", a * n);
	else {
		ll sum = 0;
		for (int i = 1; i <= n; i++)
			sum += (ll)(t - rec[i]) * (c - b) + a;
		printf("%lld\n", sum);
	}
	return 0;
}
