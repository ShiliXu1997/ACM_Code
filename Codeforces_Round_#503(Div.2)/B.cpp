//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月11日 星期六 22时14分50秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1005;

int n;
bool done[MAXN];
int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		memset(done, false, sizeof(done));
		int ans = i;
		bool flag = false;
		while (!flag) {
			if (!done[ans])
				done[ans] = true, ans = a[ans];
			else
				flag = true;
		}
		printf("%d ", ans);
	}
	return 0;
}
