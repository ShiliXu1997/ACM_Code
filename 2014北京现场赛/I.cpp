//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 05 Oct 2018 12:27:18 PM CST
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

const double PI = acos(-1);

struct point {
    double x, y;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

double area(point a, double r1, point b, double r2)
{
    double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (d >= r1 + r2)
        return 0;
    if (r1 > r2) {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if (r2 - r1 >= d) return PI * r1 * r1;
    double ang1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    double ang2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    return ang1 * r1 * r1 + ang2 * r2 * r2 - r1 * d * sin(ang1);
}

int t;
double r, R;
double x[2], y[2];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%lf %lf", &r, &R);
        scanf("%lf %lf", &x[0], &y[0]);
        scanf("%lf %lf", &x[1], &y[1]);
        point p1 = point(x[0], y[0]), p2 = point(x[1], y[1]);
        double ans = area(p1, R, p2, R) - area(p1, R, p2, r) - area(p1, r, p2, R) + area(p1, r, p2, r);
        printf("Case #%d: %.6f\n", kase, ans);
    }
	return 0;
}
