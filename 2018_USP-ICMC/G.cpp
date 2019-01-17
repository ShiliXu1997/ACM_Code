//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 06 Oct 2018 02:46:45 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5;
const double EPS = 1e-7;

int sgn(double x)
{
    if (fabs(x) < EPS) return 0;
    return (x > 0 ? 1 : -1);
}

struct car {
    double s, v;

    bool operator<(const car &another) const
    {
        return sgn(s - another.s) < 0;
    }
};

int n;
car a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf %lf", &a[i].s, &a[i].v);
    sort(a + 1, a + 1 + n);
    bool flag = true;
    for (int i = 2; i <= n && flag; i++)
        if (sgn(a[i - 1].v - a[i].v) > 0) flag = false;
    if (flag)
        printf("0\n");
    else {
        int mn = n;
        double ans = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (sgn(a[i].v - a[mn].v) <= 0)
                mn = i;
            else
                ans = max(ans, (a[mn].s - a[i].s) / (a[i].v - a[mn].v));
        }
        printf("%.6f\n", ans);
    }
	return 0;
}
