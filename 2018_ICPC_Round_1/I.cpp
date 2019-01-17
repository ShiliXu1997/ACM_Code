//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月31日 星期五 12时46分47秒
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

const int MAXN = 1e6 + 6;

int n, q, k, head, tail;
char s[MAXN];
int que[MAXN], pre[MAXN];

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		if (s[i] == '1') pre[i]++;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &k);
		head = tail = 0;
		que[tail++] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			while (head < tail && que[tail - 1] - 2 * pre[que[tail - 1]] > i - 2 * pre[i]) tail--;
			que[tail++] = i;
			while (head < tail && pre[que[tail - 1]] - pre[que[head]] > k) head++;
			ans = max(ans, k + (que[tail - 1] - 2 * pre[que[tail - 1]]) - (que[head] - 2 * pre[que[head]]));
		}
		ans = min(ans, n - pre[n]);
		printf("%d\n", ans);
	}
	return 0;
}
