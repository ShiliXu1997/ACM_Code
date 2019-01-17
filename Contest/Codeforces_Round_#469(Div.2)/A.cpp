//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月09日 星期五 16时14分09秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int l, r, a;

int main()
{
	scanf("%d %d %d", &l, &r, &a);
	if (l > r) swap(l, r);
	if (r - l >= a)
		printf("%d", 2 * (l + a));
	else
		printf("%d", (r + (a - r + l) / 2) * 2);
	return 0;
}
