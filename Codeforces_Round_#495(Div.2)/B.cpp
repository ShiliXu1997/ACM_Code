//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月06日 星期五 01时05分29秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int l, r;
		scanf("%d %d", &l, &r);
	}
	int now = 0;
	for (int i = 1; i <= n; i++) printf("%d", now), now ^= 1;
	return 0;
}
