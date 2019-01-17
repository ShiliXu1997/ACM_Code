//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月30日 星期五 13时33分49秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, st, ed;

int func(int l, int st, int ed, int r)
{
	if (l < st && st + 1 == ed && ed < r) return -1;
	if (l == st && st + 1 == ed || ed == r && st + 1 == ed) return 1;
	if ((l == st || ed == r) && (ed - st + 1) % 3 == 0) return (ed - st + 1) / 3 + 1;
	if ((l == st || ed == r) && (ed - st + 1) % 3 == 1) {
		if (l == st && ed == r)
			return (ed - st + 1) / 3;
		else
			return (ed - st + 1) / 3 + 2;
	}
	if ((l == st || ed == r) && (ed - st + 1) % 3 == 2) return (ed - st + 1) / 3 + 1;
	return func(l, st, ed - 1, ed - 1) + 1;
}

int main()
{
	scanf("%d %d %d", &n, &st, &ed);
	if (st > ed) swap(st, ed);
	printf("%d\n", func(1, st, ed, n));
	return 0;
}
