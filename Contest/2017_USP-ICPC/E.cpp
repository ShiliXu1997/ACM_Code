//************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月01日 星期二 17时41分48秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const double EPS = 1e-8;

struct point {
    double x, y;

	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
	
	bool operator<(const point &another) const
	{
		return (x == another.x ? (y < another.y) : x < another.x);
	}

	bool operator!=(const point &another) const
	{
		return (fabs(x - another.x) > EPS || fabs(y - another.y) > EPS);
	}
};

int n, m;
vector<point> p, t, all, pol;

int sgn(double x)
{
    if (fabs(x) < EPS) return 0;
    if (x > 0)
        return 1;
    else
        return -1;
}

double det(const point &a1, const  point &a2, const point &b1, const point &b2)
{
    return ((a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x));
}

double dist(const point &p1, const point &p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

bool cmp(const point &a, const point &b)
{
	if (sgn(det(all[0], a, all[0], b)) == 0)
		return sgn(dist(all[0], a) - dist(all[0], b)) < 0;
	else
		return sgn(det(all[0], a, all[0], b)) > 0;
}

vector<point> graham(vector<point> &o)
{
	double min_y = o[0].y, min_x = o[0].x;
	vector<point> ans;
	int index = 0;
	for (int i = 1; i < o.size(); i++)
		if (sgn(o[i].y - min_y) < 0 || (sgn(o[i].y - min_y) == 0 && sgn(o[i].x - min_x) < 0)) {
			min_y = o[i].y;
			min_x = o[i].x;
			index = i;
		}
	swap(o[0], o[index]);
	sort(o.begin() + 1, o.end(), cmp);
	ans.push_back(o[0]); ans.push_back(o[1]);
	for (int i = 2; i < o.size(); i++) {
		while (ans.size() >= 2 && sgn(det(ans.back(), o[i], ans.back(), ans[ans.size() - 2])) < 0)
			ans.pop_back();
		ans.push_back(o[i]);
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		p.push_back(point(x, y));
		all.push_back(point(x, y));
	}
	for (int i = 1; i <= m; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		t.push_back(point(x, y));
		all.push_back(point(x, y));
	}
	pol = graham(all);
	if (p.size() == pol.size() || t.size() == pol.size())
		printf("YES");
	else
		printf("NO");
	return 0;
}
