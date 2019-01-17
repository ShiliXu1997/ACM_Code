//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月30日 星期一 12时22分12秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int t;

int main()
{
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);
		if (k == 1) {
			printf("%d\n", 5);
			continue;
		}
		else
			printf("%d\n", k + 5);
	}
	return 0;
}
