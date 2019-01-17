//************************************************************************
// File Name: S.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月18日 星期日 15时06分23秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct box {
	int pos, value;
	
	bool operator<(const box &another) const
	{
		if (value == another.value)
			return pos < another.pos;
		return value < another.value;
	}
};

char s[MAXN];
box e[MAXN];

int main()
{
	scanf("%s", s);
	e[1].pos = 1;
	if (s[0] == 'B')
		e[1].value = 1;
	else
		e[1].value = -1;
	int len = strlen(s);
	for (int i = 2; i <= len; i++) {
		e[i].pos = i;
		e[i].value = e[i - 1].value;
		if (s[i - 1] == 'B')
			e[i].value++;
		else
			e[i].value--;
	}
	sort(e + 1, e + 1 + len);
	int i = 1, j = len;
	while (e[j - 1].value == e[j].value) j--;
	if (e[1].value == 0) {
		i = 1;
		j = e[j].pos;
	}
	else
	if (e[len].value == 0) {
		i = e[i].pos;
		j = 1;
	}
	else {
		i = e[i].pos; j = e[j].pos;
	}
	if (i > j) swap(i, j);
	if (e[1].value >= 0 && e[len].value >= 0 || e[1].value <= 0 && e[len].value <= 0)
		printf("%d %d", i, j);
	else
		printf("%d %d", i + 1, j);
	return 0;
}
