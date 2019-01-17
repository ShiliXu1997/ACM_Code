//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月17日 星期五 23时12分46秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, k;
char s[MAXN], ans[MAXN];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	ans[k] = '\0';
	int cnt = 0, tot = k / 2;
	for (int i = 0; i < n && cnt < k; i++) {
		if (s[i] == '(' && tot) {
			tot--;
			ans[cnt++] = '(';
		}
		if (s[i] == ')') ans[cnt++] = ')';
	}
	printf("%s", ans);
	return 0;
}
