//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月26日 星期一 00时00分14秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 605;

int sc[MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &sc[i]);
	sc[0] = -1;
	sort(sc + 1, sc + 1 + n);
	int i = 1, ans = 0;
	while (sc[i] == 0) i++;
	while (i <= n) {
		if (sc[i] != sc[i - 1]) ans++;
		i++;
	}
	printf("%d\n", ans);
	return 0;
}

