//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月10日 星期二 22时46分41秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

int n, a, b;
char s[MAXN];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", s);
	int len = strlen(s), ans = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i - 1] == '.') {
			bool flag = false;
			if (a >= b && a) {
				if (i == 1 || i >= 2 && s[i - 2] != 'a') {
					a--;
					ans++;
					s[i - 1] = 'a';
					flag = true;
				}
			}
			if (!flag && b) {
				if (i == 1 || i >= 2 && s[i - 2] != 'b') {
					b--;
					ans++;
					s[i - 1] = 'b';
					flag = true;
				}
			}
			if (!flag && a) {
				if (i == 1 || i >= 2 && s[i - 2] != 'a') {
					a--;
					ans++;
					s[i - 1] = 'a';
					flag = true;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
