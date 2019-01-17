//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 23时37分42秒
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

const int MAXN = 1e5 + 5;

int n, k;
char s[MAXN];
int cnt[30];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[s[i] - 'A']++;
	int mn = 0x3f3f3f3f;
	for (int i = 0; i < k; i++) mn = min(mn, cnt[i]);
	printf("%d\n", k * mn);
	return 0;
}
