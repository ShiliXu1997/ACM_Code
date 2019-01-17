//******************************************************************************
// File Name: POJ_2007.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月18日 星期三 20时52分32秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

struct point {
	int x, y;

	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	
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

double length(vec a)
{
	return sqrt(dot(a, a));
}

struct line {
	point s, e;

	line() {}
	line(point _s, point _e) : s(_s), e(_e) {}
};

vector<point> p;

bool cmp(const point &a, const point &b)
{
	double crs = det(a - p[0], b - p[0]); 
	if (sgn(crs) == 0)
		return sgn(length(a - p[0]) - length(b - p[0])) < 0;
	return sgn(crs) > 0;
}

void sort_by_angle()
{
	int pos = 0;
	for (int i = 1; i < p.size(); i++)
		if (p[i].y < p[pos].y || (p[i].y == p[pos].y && p[i].x < p[pos].x)) pos = i;
	swap(p[pos], p[0]);
	sort(p.begin(), p.end(), cmp);
}

int main()
{
	freopen("in.txt", "r", stdin);
	int x, y;
	while (scanf("%d %d", &x, &y) == 2) p.push_back(point(x, y));
	sort_by_angle();
	int index;
	for (int i = 0; i < p.size(); i++)
		if (sgn(p[i].x) == 0 && sgn(p[i].y) == 0) {
			index = i;
			break;
		}
	for (int i = index; i < p.size(); i++) printf("(%d,%d)\n", p[i].x, p[i].y);
	for (int i = 0; i < index; i++) printf("(%d,%d)\n", p[i].x, p[i].y);
	return 0;
}
