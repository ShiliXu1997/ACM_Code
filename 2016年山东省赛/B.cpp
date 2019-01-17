//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月03日 星期四 15时13分58秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 30;

int t, n;
int num[MAXN], way[MAXN];

void init()
{
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i < MAXN; i++) num[i] = num[i - 1] + num[i - 2];
}

bool dfs(int pos, int index, int sum, int tar)
{
	way[pos] = num[index];
	sum += num[index];
	if (sum > tar) return false;
	if (sum == tar) {
		printf("%d=", tar);
		for (int i = 1; i < pos; i++) printf("%d+", way[i]); printf("%d\n", way[pos]);
		return true;
	}
	for (int i = index + 2; i < MAXN; i++) if (dfs(pos + 1, i, sum, tar)) return true;
	return false;
}

int main()
{
	init();
	scanf("%d", &t);
	for (int m = 1; m <= t; m++) {
		scanf("%d", &n);
		bool flag = false;
		for (int i = 1; i < MAXN && !flag; i++) if (dfs(1, i, 0, n)) flag = true;
		if (!flag) printf("-1\n");
	}
	return 0;
}
