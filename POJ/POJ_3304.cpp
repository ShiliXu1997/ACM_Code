//******************************************************************************
// File Name: POJ_3304.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月17日 星期二 15时48分00秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 205;
const double EPS = 1e-8;

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

struct point {
	double x, y;

	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	
	bool operator<(const point &another) const
	{
		return (x < another.x) || (x == another.x && y < another.y);
	}

	bool operator==(const point &another) const
	{
		return sgn(x - another.x) == 0 && sgn(y - another.y) == 0;
	}
};

typedef point vec;

vec operator+(vec a, vec b)
{
	return vec(a.x + b.x, a.y + b.y);
}

vec operator-(point a, point b)
{
	return vec(a.x - b.x, a.y - b.y);
}

vec operator*(vec a, double p)
{
	return vec(a.x * p, a.y * p);
}

vec operator/(vec a, double p)
{
	return vec(a.x / p, a.x / p);
}

double dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}

double det(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

struct line {
	point s, e;

	line() {}
	line(point _s, point _e) : s(_s), e(_e) {}
};

bool isinter_seg_line(line l1, line l2)
{
	return sgn(det(l2.e - l2.s, l1.s - l2.s)) * sgn(det(l2.e - l2.s, l1.e - l2.s)) <= 0;
}

int t, n;
line seg[MAXN];

bool check(line l)
{
	if (l.s == l.e) return false;
	for (int i = 1; i <= n; i++)
		if (!isinter_seg_line(seg[i], l)) return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf %lf %lf", &seg[i].s.x, &seg[i].s.y, &seg[i].e.x, &seg[i].e.y);
		if (n <= 2) {
			printf("Yes!\n");
			continue;
		}
		bool flag = false;
		for (int i = 1; i < n && !flag; i++)
			for (int j = i + 1; j <= n && !flag; j++)
				if (check(line(seg[i].s, seg[j].s)) || check(line(seg[i].s, seg[j].e))
					|| check(line(seg[i].e, seg[j].s)) || check(line(seg[i].e, seg[j].e)))
					flag = true;	
			
		if (flag)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}
