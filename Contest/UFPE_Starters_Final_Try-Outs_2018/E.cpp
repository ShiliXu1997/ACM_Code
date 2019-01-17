//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月12日 星期六 22时35分26秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 3005;

int k;
char s[MAXN];
int cnt[MAXN][MAXN];

int main()
{
	scanf("%s %d", s, &k);
	int len = strlen(s), ans = len;
	memset(cnt, 0, sizeof(cnt));
	for (int i = len - 2; i >= 0; i--)
		for (int j = i + 1; j < len; j++) {
			cnt[i][j] = cnt[i + 1][j - 1] + (int)(s[i] != s[j]);
			if (cnt[i][j] <= k) ans++;
		}
	printf("%d\n", ans);
	return 0;
}
