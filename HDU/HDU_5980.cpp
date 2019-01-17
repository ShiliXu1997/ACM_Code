//************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月25日 星期日 13时42分26秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
	while (scanf("%d", &n) == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x, cnt = 0;
			scanf("%d", &x);
			if (x % 256 == 97) cnt++;
			for (int j = 1; j <= 3; j++) {
				x >>= 8;
				if (x % 256 == 97) cnt++;
			}
			ans += cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}

