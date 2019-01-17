//******************************************************************************
// File Name: L.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月01日 星期三 12时11分03秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;
const int MAXN = 1e5 + 5;

int t, n;
int w[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
		printf("%d\n", (int)(sqrt(abs(w[n] - w[1])) + EPS));
	}
	return 0;
}
