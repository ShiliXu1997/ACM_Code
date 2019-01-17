//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 17时33分15秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int n;
int a[MAXN], pos[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) pos[a[i]] = i;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (pos[a[i]] == i) cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (pos[a[i]] == i) printf("%d ", a[i]);
	return 0;
}
