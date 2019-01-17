//******************************************************************************
// File Name: POJ_2653.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月17日 星期二 17时06分54秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
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

bool isinter_seg_seg(line l1, line l2)
{
	return (max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x)
		&& max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y))//排斥实验
		&& (sgn(det(l1.e - l1.s, l2.s - l1.s) * det(l1.e - l1.s, l2.e - l1.s)) <= 0
		&& sgn(det(l2.e - l2.s, l1.s - l2.s) * det(l2.e - l2.s, l1.e - l2.s)) <= 0);//跨立测试
}

int n;
line segment[MAXN];
bool flag[MAXN];

int main()
{
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf %lf %lf", &segment[i].s.x, &segment[i].s.y, &segment[i].e.x, &segment[i].e.y);
		for (int i = 1; i <= n; i++) {
			flag[i] = true;
			for (int j = i + 1; j <= n; j++)
				if (isinter_seg_seg(segment[i], segment[j])) {
					flag[i] = false;
					break;
				}
		}
		printf("Top sticks: ");
		bool first = false;
		for (int i = 1; i <= n; i++) {
			if (flag[i]) {
				if (!first)
					first = true;
				else
					printf(", ");
				printf("%d", i);
			}
		}
		printf(".\n");
	}
	return 0;
}
