//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月29日 星期日 21时13分18秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 105;

int n, s;
int time[MAXN];

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		int h, m;
		scanf("%d %d", &h, &m);
		time[i] = h * 60 + m;
	}
	if (1 + s <= time[1]) {
		printf("0 0\n");
		return 0;
	}
	int ans = -1;
	for (int i = 1; i <= n - 1 && ans == -1; i++) {
		if (time[i] + 2 + 2 * s  <= time[i + 1]) ans = time[i] + 1 + s;
	}
	int hh, mm;
	if (ans == -1) {
		hh = (time[n] + 1 + s) / 60;
		mm = (time[n] + 1 + s) % 60;
	}
	else {
		hh = ans / 60;
		mm = ans % 60;
	}
	printf("%d %d\n", hh, mm);
	return 0;
}
