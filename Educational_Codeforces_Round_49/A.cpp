//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月18日 星期六 22时38分24秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 105;

int t, n;
char s[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &n, s);
		bool flag = true;
		for (int i = 0; i < n && flag; i++) {
			if (abs(s[i] - s[n - i - 1]) == 2 || s[i] == s[n - i - 1]) continue;
			flag = false;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
