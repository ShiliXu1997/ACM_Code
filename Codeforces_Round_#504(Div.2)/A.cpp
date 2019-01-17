//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月17日 星期五 22时34分57秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, m;
char s[MAXN], t[MAXN];

bool notletter(char x)
{
	return !('a' <= x && x <= 'z');
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);
	if (n - 1 > m)
		printf("NO\n");
	else {
		int pos = -1;
		bool flag = true;
		for (int i = 0; i < m; i++)
			if (notletter(t[i])) {
				flag = false;
				break;
			}
		bool find = false;
		for (int i = 0; i < n; i++)
			if (s[i] == '*') {
				pos = i;
				find = true;
				break;
			}
		if (find) {
			for (int i = 0; i < pos; i++)
				if (s[i] != t[i]) {
					flag = false;
					break;
				}
			for (int i = n - 1, j = m - 1; i > pos; i--, j--)
				if (s[i] != t[j]) {
					flag = false;
					break;
				}
		}
		else {
			if (n != m) flag = false;
			for (int i = 0; i < n && flag; i++)
				if (s[i] != t[i]) flag = false;
		}
		printf("%s", flag ? "YES\n" : "NO\n");
	}
	return 0;
}
