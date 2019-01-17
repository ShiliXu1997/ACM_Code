//******************************************************************************
// File Name: POJ_3608.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月20日 星期五 21时39分44秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

const double EPS = 1e-8, INF = 1e17;

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

double length(vec a)
{
	return sqrt(dot(a, a));
}

struct line {
	point s, e;

	line() {}
	line(point _s, point _e) : s(_s), e(_e) {}
};

bool ison_point_line(point p, line l)
{
	return sgn(det(p - l.s, p - l.e)) == 0;
}

double dist_point_seg(point p, line l)
{
	vec v1 = l.e - l.s, v2 = p - l.s, v3 = p - l.e;
	if (sgn(dot(v1, v2)) < 0) return length(v2);
	if (sgn(dot(v1, v3)) > 0) return length(v3);
	return fabs(det(v1, v2) / length(v1));
}

double dist_seg_seg(line seg1, line seg2)
{
	double d1 = min(dist_point_seg(seg1.s, seg2), dist_point_seg(seg1.e, seg2));
	double d2 = min(dist_point_seg(seg2.s, seg1), dist_point_seg(seg2.e, seg1));
	return min(d1, d2);
}

struct polygon {
	vector<point> p;
	
	polygon() {}
	polygon(vector<point> v)
	{
		p = v;
	}
};

polygon convex_hull(vector<point> all)
{
	polygon ans;
	vector<point> &v = ans.p;
	sort(all.begin(), all.end());
	for (int i = 0; i < all.size(); i++) {
		while (v.size() > 1 && sgn(det(v.back() - v[v.size() - 2], all[i] - v[v.size() - 2])) <= 0)
			v.pop_back();
		v.push_back(all[i]);
	}
	int k = v.size();
	for (int i = all.size() - 2; i >= 0; i--) {
		while (v.size() > k && sgn(det(v.back() - v[v.size() - 2], all[i] - v[v.size() - 2])) <= 0)
			v.pop_back();
		v.push_back(all[i]);
	}
	if (all.size() > 1) v.pop_back();
	return ans;
}

double rotating_calipers(polygon p, polygon q)
{
	double ans = INF;
	int sp = 0, sq = 0, psz = p.p.size(), qsz = q.p.size();
	for (int i = 1; i < psz; i++)
		if (sgn(p.p[i].y - p.p[sp].y) < 0) sp = i;
	for (int i = 1; i < qsz; i++)
		if (sgn(q.p[i].y - q.p[sq].y) > 0) sq = i;
	for (int i = 0; i < psz; i++) {
		while (sgn(det(p.p[(sp + 1) % psz] - p.p[sp], q.p[sq] - q.p[(sq + 1) % qsz])) < 0)
			sq = (sq + 1) % qsz;
		if (sgn(det(p.p[(sp + 1) % psz] - p.p[sp], q.p[sq] - q.p[(sq + 1) % qsz])) == 0)
			ans = min(ans, dist_seg_seg(line(p.p[sp], p.p[(sp + 1) % psz]), line(q.p[sq], q.p[(sq + 1) % qsz])));
		else
			ans = min(ans, dist_point_seg(q.p[sq], line(p.p[sp], p.p[(sp + 1) % psz])));
		sp = (sp + 1) % psz;
	}
	return ans;
}

int n, m;
vector<point> all_n, all_m;
polygon p, q;

int main()
{
	while (scanf("%d %d", &n, &m) == 2 && (n * m)) {
		all_n.clear();
		all_m.clear();
		for (int i = 1; i <= n; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			all_n.push_back(point(x, y));
		}
		for (int i = 1; i <= m; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			all_m.push_back(point(x, y));
		}
		p = convex_hull(all_n);
		q = convex_hull(all_m);
		double ans = min(rotating_calipers(p, q), rotating_calipers(q, p));
		printf("%f\n", ans);
	}
	return 0;
}
