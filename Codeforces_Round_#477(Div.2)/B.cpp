//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月29日 星期日 21时37分28秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;
ll a, b;
ll s[MAXN];

int main()
{
	scanf("%d %lld %lld", &n, &a, &b);
	ll sum = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &s[i]), sum += s[i];
	sort(s + 2, s + 1 + n);
	int ans = 0;
	for (int i = n; i >= 2; i--) {
		if (s[1] * a >= sum * b) break;
		sum -= s[i]; ans++;
	}
	printf("%d\n", ans);
	return 0;
}
