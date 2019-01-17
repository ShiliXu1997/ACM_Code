//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月10日 星期二 22时35分15秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN];

int main()
{
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
	long long now = 0;
	int ans;
	for (int i = 1; i <= n; i++) {
		now += a[i];
		if (now >= (sum + 1) / 2) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
