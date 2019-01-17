//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月24日 星期六 19时41分49秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int t, n, m;
char s[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		scanf("%s", s);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) printf("%c", s[(i - 1) * m + j - 1]);
			printf("\n");
		}
	}
	return 0;
}

