//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 03 Oct 2018 12:28:09 PM CST
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
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5;

struct point {
    ll x, y;

    point() {}
    point(ll _x, ll _y) : x(_x), y(_y) {}
};

typedef point vec;

vec operator-(point a, point b)
{
    return vec(a.x - b.x, a.y - b.y);
}

ll det(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}

ll dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}

struct line {
    point s, e;

    line() {}
    line(point _s, point _e) : s(_s), e(_e) {}
};

bool ison_point_line(point p, line l)
{
    return det(p - l.s, p - l.e) == 0;
}

int n, q;
point p[MAXN];

int main()
{
    srand(time(NULL));
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
    if (n <= 2) {
        printf("possible\n");
        return 0;
    }
    bool flag = false;
    for (int kase = 1; kase <= 500 && !flag; kase++) {
        int a = rand() * rand() % n + 1, b = a;
        while (b == a) b = rand() * rand() % n + 1;
        line l = line(p[a], p[b]);
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (ison_point_line(p[i], l)) cnt++;
        if (cnt * 100 >= q * n) flag = true;
    }
    if (flag)
        printf("possible\n");
    else
        printf("impossible\n");
	return 0;
}
