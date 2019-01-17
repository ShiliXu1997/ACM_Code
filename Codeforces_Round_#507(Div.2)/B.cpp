//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 00时49分20秒
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

int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	int mn = 0x3f3f3f3f, pos = 0;
	for (int i = 1; i <= k + 1; i ++) {
		int cnt = 0, last = 0;
		for (int j = i; j <= n; j += 2 * k + 1) {
			cnt++;
			last = j + k;
		}
		if (last >= n) mn = min(mn, cnt), pos = i;
	}
	printf("%d\n", mn);
	for (int i = pos; i <= n; i += 2 * k + 1) printf("%d ", i);
	return 0;
}
