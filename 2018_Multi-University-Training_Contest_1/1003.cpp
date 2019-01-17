//******************************************************************************
// File Name: 1003.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月24日 星期二 20时27分46秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;
const int MAXN = 3005;

struct point {
	int id, x, y;

	bool operator<(const point &another) const
	{
		return x - another.x < 0;
	}
};

int t, n;
point p[MAXN];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		n *= 3;
		for (int i = 1; i <= n ;i++)
			scanf("%d %d", &p[i].x, &p[i].y), p[i].id = i;
		sort(p + 1, p + 1 + n);
		for (int i = 1; i <= n; i += 3)
			printf("%d %d %d\n", p[i].id, p[i + 1].id, p[i + 2].id);
	}
	return 0;
}
