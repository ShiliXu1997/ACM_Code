//******************************************************************************
// File Name: POJ_1410.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月18日 星期三 19时50分59秒
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

bool ison_point_seg(point p, line l)
{
	return sgn(det(p - l.s, p - l.e)) == 0 && sgn(dot(p - l.s, p - l.e)) < 0;
}

bool isinter_seg_seg(line l1, line l2)
{
	return (max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x)
		&& max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y))//排斥实验
		&& (sgn(det(l1.e - l1.s, l2.s - l1.s) * det(l1.e - l1.s, l2.e - l1.s)) <= 0
		&& sgn(det(l2.e - l2.s, l1.s - l2.s) * det(l2.e - l2.s, l1.e - l2.s)) <= 0);//跨立测试
}

struct polygon {
	vector<point> p;
	
	polygon() {}
	polygon(vector<point> v)
	{
		p = v;
	}

	//点和多边形的关系，返回0是在外面，1是在里面，2是在边上
	int relation_point(point t)
	{
		int cnt = 0;
		for (int i = 0; i < p.size(); i++) {
			if (ison_point_seg(t, line(p[i], p[(i + 1) % p.size()]))) return 2;
			int k = sgn(det(p[(i + 1) % p.size()] - p[i], t - p[i]));
			int d1 = sgn(p[i].y - t.y), d2 = sgn(p[(i + 1) % p.size()].y - t.y);
			if (k > 0 && d1 <= 0 && d2 > 0) cnt++;
			if (k < 0 && d2 <= 0 && d1 > 0) cnt--;
		}
		return cnt != 0;
	}
};

int n;

bool check(polygon rec, line seg)
{
	if (rec.relation_point(seg.s) || rec.relation_point(seg.e)) return true;
	for (int i = 0; i < 4; i++)
		if (isinter_seg_seg(seg, line(rec.p[i], rec.p[(i + 1) % 4]))) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		line seg;
		scanf("%lf %lf %lf %lf", &seg.s.x, &seg.s.y, &seg.e.x, &seg.e.y);
		polygon rec;
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		rec.p.push_back(point(x1, y1));	
		rec.p.push_back(point(x1, y2));
		rec.p.push_back(point(x2, y2));
		rec.p.push_back(point(x2, y1));
		if (check(rec, seg))
			printf("T\n");
		else
			printf("F\n");
	}
	return 0;
}
