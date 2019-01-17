//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月28日 星期二 13时31分54秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 105;

char s[MAXN], t[MAXN];
int cnt[26];
int n, m;

bool check()
{
	bool flag = true;
	if ((n + m) % 2 == 0) {
		for (int i = 0; i < 26 && flag; i++)
			if (cnt[i] & 1) flag = false;
	}
	else {
		int now = 0;
		for (int i = 0; i < 26; i++)
			if (cnt[i] & 1) now++;
		if (now > 1) flag = false;
	}
	return flag;
}

int main()
{
	scanf("%s %s", s, t);
	n = strlen(s), m = strlen(t);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < m; i++) cnt[t[i] - 'a']++;
	if (check())
		puts("YES");
	else
		puts("NO");
	return 0;
}
