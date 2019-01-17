//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 22时04分54秒
//************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;

int n;
char s[MAXN];
set<string> st;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		int len = strlen(s);
		sort(s, s + len);
		len = (int)(unique(s, s + len) - s);
		s[len] = '\0';
		string str(s);
		st.insert(str);
	}
	printf("%d", (int)st.size());
	return 0;
}
