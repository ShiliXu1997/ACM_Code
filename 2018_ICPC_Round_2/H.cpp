//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 12时39分48秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 5005;

int n;
int a[MAXN];

bool check(int r)
{
	if (a[r - 2] <= a[r - 1] && a[r - 1] <= a[r]) return false;
	if (a[r - 2] >= a[r - 1] && a[r - 1] >= a[r]) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ans = 2;
	for (int l = 1; l <= n - 2; l++) {
		int r = l + 1;
		while (r < n && check(r + 1)) r++;
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
