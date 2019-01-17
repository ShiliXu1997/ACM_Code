//******************************************************************************
// File Name: 1011.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月24日 星期二 22时41分25秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int t;
char s[10];

int main()
{
	scanf("%d", &t);
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%s", s);
		int beijing = x * 60 + y;
		int len = strlen(s);
		double dz;
		if (len == 5) dz = (s[3] == '+' ? 1.0 : -1.0) * (s[4] - '0');
		if (len == 6) dz = (s[3] == '+' ? 1.0 : -1.0) * ((s[4] - '0') * 10 + (s[5] - '0'));
		if (len == 7) dz = (s[3] == '+' ? 1.0 : -1.0) * (s[4] - '0' + 0.1 * (s[6] - '0'));
		if (len == 8) dz = (s[3] == '+' ? 1.0 : -1.0) * ((s[4] - '0') * 10 + (s[5] - '0') + 0.1 * (s[7] - '0'));
		dz -= 8.0;
		int dm = (dz > 0 ? 1 : -1) * (int)(fabs(dz) * 60 + EPS);
		int ans = dm + beijing + 24 * 60, h = ans % (24 * 60) / 60, m = ans % (24 * 60) % 60;
		printf("%.2d:%.2d\n", h, m);
	}
	return 0;
}
