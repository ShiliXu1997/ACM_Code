//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 13时00分34秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

int sgn(double x)
{
	if (fabs(x - 0) < EPS) return 0;
	return (x < 0 ? -1 : 1);
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

struct polygon {
	vector<point> p;
	
	polygon() {}
	polygon(vector<point> v)
	{
		p = v;
	}
	
	double area()
	{
		double ans = 0;
		for (int i = 1; i < p.size() - 1; i++)
			ans += det(p[i] - p[0], p[i + 1] - p[0]);
		return fabs(ans / 2);
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

int t, n;
vector<point> p;
polygon pol;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		p.clear();
		for (int i = 1; i <= n; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			p.push_back(point(x, y));
		}
		pol = polygon(p);
		printf("%.6f\n", pol.area());
	}
	return 0;
}
