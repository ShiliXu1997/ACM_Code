//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年01月26日 星期五 00时48分21秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int x, h, m;
	scanf("%d", &x);
	scanf("%d %d", &h, &m);
	int minutes = h * 60 + m;
	int ans = 0;
	while (true) {
		h = minutes / 60;
		m = minutes % 60;
		if (h % 10 == 7 || m % 10 == 7)
			break;
		else {
			minutes -= x;
			if (minutes < 0) minutes += 24 * 60;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}

