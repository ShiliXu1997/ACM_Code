//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月19日 星期日 21时38分53秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n;
char s[MAXN];
int cnt[26];

int main()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	bool flag = false;
	for (int i = 0; i <= 25; i++)
		if (cnt[i] >= 2) flag = true;
	printf("%s\n", n == 1 || flag ? "Yes" : "No");
	return 0;
}
