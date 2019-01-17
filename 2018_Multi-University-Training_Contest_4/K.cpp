//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月01日 星期三 13时12分23秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 505;

int t;
char s[MAXN];

bool check(char *str, int n)
{
	if (s[0] == '+' || s[0] == '*'|| s[n - 1] == '+' || s[n - 1] == '*') return false;
	if (s[0] == '?') s[0] = '1';
	if (s[n - 1] == '?') s[n - 1] = '1';
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '?') {
			if (s[i - 1] == '0') {
				if (i - 2 < 0 || (i - 2 >= 0 && (s[i - 2] == '+' || s[i - 2] == '*')))
					s[i] = '+';
				else
					s[i] = '1';
			}
			else
				s[i] = '1';
		}
		if ((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*')) return false;
	}
	for (int i = 0; i < n - 1; i++) {
		if ((s[i] == '+' || s[i] == '*') && (s[i - 1] == '+' || s[i - 1] == '*')) return false;
		if ((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*')) return false;
		if (s[i] == '0' && (i - 1 < 0 || s[i - 1] == '+' || s[i - 1] == '*') && (s[i + 1] != '+' && s[i + 1] != '*')) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int len = strlen(s);
		if (check(s, len))
			printf("%s\n", s);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
