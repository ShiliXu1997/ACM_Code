//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 11时48分47秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 2e5 + 5;

struct zebra {
	int last, num;
};

char s[MAXN];
zebra a[MAXN];
stack<int> good, bad;

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 1; i <= len; i++) {
		a[i].last = 0;
		a[i].num = 1;
	}
	bool flag = true;
	for (int i = len; i >= 1; i--) {
		if (s[i - 1] == '0') {
			if (!bad.empty()) {
				int u = bad.top(); bad.pop();
				a[i].last = u;
				a[i].num = a[u].num + 1;
				good.push(i);
			}
			else
				good.push(i);
		}
		else {
			if (!good.empty()) {
				int u = good.top(); good.pop();
				a[i].last = u;
				a[i].num = a[u].num + 1;
				bad.push(i);
			}
			else
				flag = false;
		}
	}
	if (!flag || bad.size() != 0)
		printf("-1");
	else {
		printf("%d\n", (int)good.size());
		while (!good.empty()) {
			int u = good.top(); good.pop();
			printf("%d ", a[u].num);
			while (u) {
				printf("%d ", u);
				u = a[u].last;
			}
			printf("\n");
		}
	}
	return 0;
}
