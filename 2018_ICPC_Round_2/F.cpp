//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 19时18分08秒
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

const int MAXN = 1e6 + 5;

int q;
char s[MAXN];
map<string, int> mp;
string now;

int main()
{
	scanf("%d", &q);
	scanf("%s", s);
	now = string("");
	for (int i = 0; i < q; i++) {
		if (s[i] == '-') {
			now.pop_back();
			printf("%d ", mp[now]);
		}
		else {
			int base = mp[now];

		}
	}
	return 0;
}
