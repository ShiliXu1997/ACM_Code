//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月10日 星期六 14时18分42秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int s;
char chess[2];

int main()
{
	while (scanf("%d", &s) == 1) {
		scanf("%s", chess);
		if (chess[0] == 'K') printf("%d\n", (s == 1) ? 1 : 4);
		if (chess[0] == 'R' || chess[0] == 'B') printf("%d\n", s);
		if (chess[0] == 'N')  printf("%d\n", (s >= 3) ? 2 : 1);
	}
	return 0;
}
