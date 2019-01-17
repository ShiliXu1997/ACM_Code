//************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月07日 星期六 01时02分11秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int cnt = 1;
		for (int i = 1; i <= n - 1; i++) {
			int x;
			scanf("%d", &x);
			if (x == 1) {
				if (cnt)
					cnt--;
				else
					cnt++;
			}
			else
				cnt++;
		}
		printf("%s\n", !cnt ? "Yes" : "No");
	}
	return 0;
}
