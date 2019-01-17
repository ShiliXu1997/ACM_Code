//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月30日 星期一 22时38分40秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200;

int n;
char s[MAXN];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int cnt_1 = 0, cnt_2 = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			cnt_1++;
		else
			cnt_2++;
	if (cnt_1) printf("1");
	for (int i = 1; i <= cnt_2; i++) printf("0");
	return 0;
}
