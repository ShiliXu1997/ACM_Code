//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月27日 星期五 13时06分44秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 35;

bool tf[MAXN];
int n, m;

int main()
{
	scanf("%d %d", &m, &n);
	int ret;
	for (int i = 1; i <= n; i++) {
		printf("1\n");
		fflush(stdout);
		scanf("%d", &ret);
		if (ret == 0) return 0;
		if (ret == 1)
			tf[i] = true;
		else
			tf[i] = false;
	}
	int l = 1, r = m, now = 0;
	for (int i = 1; i <= 30; i++) {
		int mid = (l + r) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		scanf("%d", &ret);
		if (ret == 0) return 0;
		if (tf[now = now % n + 1]) {
			if (ret == 1)
				l = mid + 1;
			else
				r = mid - 1;
		}
		else {
			if (ret == 1)
				r = mid - 1;
			else
				l = mid + 1;
		}
	}
	return 0;
}
