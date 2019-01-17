//******************************************************************************
// File Name: POJ_1269.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月17日 星期二 15时18分28秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int n;

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

typedef point vec;//向量是点的别名

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

pair<int, point> inter_line_line(line a, line b)
{
	point res = a.s;
	vec u = a.s - b.s, v= a.e - a.s, w = b.e - b.s;
	if (sgn(det(v, w)) == 0) {
		if (sgn(det(u, v)) == 0) return make_pair(0, res);//0代表重合
		return make_pair(1, res);//1代表平行
	}
	double t = det(w, u) / det(v, w);
	res = res + v * t;
	return make_pair(2, res);//2代表相交，返回交点
}

int main()
{
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	for (int i = 1; i <= n; i++) {
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		line a(point(x1, y1), point(x2, y2)), b(point(x3, y3), point(x4, y4));
		pair<int, point> res = inter_line_line(a, b);
		if (res.first == 0) printf("LINE\n");
		if (res.first == 1) printf("NONE\n");
		if (res.first == 2) printf("POINT %.2f %.2f\n", res.second.x, res.second.y);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
