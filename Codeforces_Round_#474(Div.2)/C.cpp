//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月08日 星期日 01时30分49秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10005;

int x, d;
long long ans[MAXN];

int main()
{
	scanf("%d %d", &x, &d);
	long long index = 0;
	int i = 30, cnt = 0;
	while (x) {
		while (x < (1 << i) - 1) i--;
		x -= (1 << i) - 1;
		if (index != 0)
			index += (long long)d;
		else
			index += 1;
		for (int j = 1; j <= i; j++) ans[++cnt] = index;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%lld ", ans[i]);
	return 0;
}
