//************************************************************************
// File Name: L.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 14时03分51秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char num[20];

int main()
{
	scanf("%s", num);
	int ans = 0, len = strlen(num);
	for (int i = 0; i < len; i++) ans += num[i] - '0';
	int ano = 0;
	if (num[0] != '0') ano += num[0] - '0' - 1;
	for (int i = 1; i < len; i++) ano += 9;
	ans = max(ans, ano);
	printf("%d", ans);
	return 0;
}
