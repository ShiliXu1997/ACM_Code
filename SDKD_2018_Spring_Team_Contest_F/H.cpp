//************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 09时49分20秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h;

int main()
{
	freopen("holes.in", "r", stdin);
	freopen("holes.out", "w", stdout);
	scanf("%d", &h);
	if (h == 0) {
		printf("1");
		return 0;
	}
	else
	if (h == 1) {
		printf("0");
		return 0;
	}
	if (h & 1) printf("4"), h--;
	for (int i = 1; i * 2 <= h; i++) printf("8");
	return 0;
}
