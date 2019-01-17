//******************************************************************************
// File Name: HDU_3068.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月03日 星期一 14时36分46秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 110005;

char ss[MAXN], s[MAXN << 1];
int p[MAXN << 1];

int manacher(char *str)
{
	int len = strlen(str), j = 2;
	s[0] = '$'; s[1] = '#';
	for (int i = 0; i < len; i++) s[j++] = str[i], s[j++] = '#';
	s[j] = '\0';
	int ans = 0, id = 0;
	p[0] = 0;
	for (int i = 1; i < j; i++) {
		if (i < id + p[id])
			p[i] = min(p[2 * id - i], id + p[id] - i);
		else
			p[i] = 1;
		while (s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (id + p[id] < i + p[i]) id = i;
		ans = max(ans, p[i] - 1);
	}
	return ans;
}

int main()
{
	while (scanf("%s", ss) == 1) printf("%d\n", manacher(ss));
	return 0;
}
