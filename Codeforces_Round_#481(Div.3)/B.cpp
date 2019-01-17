//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 17时38分53秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 105;

int n;
char s[MAXN];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int now = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x')
			now++;
		else
			now = 0;
		if (now == 3) {
			now = 2;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
