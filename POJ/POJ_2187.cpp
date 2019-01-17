//******************************************************************************
// File Name: POJ_2187.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月18日 星期三 22时00分53秒
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

int dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}

int det(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

int length2(vec a)
{
	return dot(a, a);
}

struct line {
	point s, e;

	line() {}
	line(point _s, point _e) : s(_s), e(_e) {}
};

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

int rotating_calipers(polygon ch)
{
	int ans = 0;
	int cur = 1, sz = ch.p.size();
	for (int i = 0; i < sz; i++) {
		vec v = ch.p[i] - ch.p[(i + 1) % sz];
		while (sgn(det(v, ch.p[(cur + 1) % sz] - ch.p[cur])) < 0)
			cur = (cur + 1) % sz;
		ans = max(ans, max(length2(ch.p[i] - ch.p[cur]), length2(ch.p[(i + 1) % sz] - ch.p[(cur + 1) % sz])));
	}
	return ans;
}

int n;
vector<point> all;
polygon ch;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		all.push_back(point(x, y));
	}
	ch = convex_hull(all);
	printf("%d\n", rotating_calipers(ch));
	return 0;
}
