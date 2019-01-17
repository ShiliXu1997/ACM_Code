//******************************************************************************
// File Name: HDU_1007.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月19日 星期四 19时02分16秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
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

int n;
vector<point> all;

bool cmp_y(const point a, const point b)
{
	return a.y < b.y;
}

double nearest_dist(int left, int right)
{
	if (left == right) return INF;
	if (left + 1 == right) return length(all[right] - all[left]);
	int mid = (left + right) >> 1;
	double d1 = nearest_dist(left, mid), d2 = nearest_dist(mid + 1, right);
	double d = min(d1, d2);
	vector<point> tmp;
	for (int i = left; i <= right; i++)
		if (sgn(d - fabs(all[i].x - all[mid].x)) >= 0) tmp.push_back(all[i]);
	sort(tmp.begin(), tmp.end(), cmp_y);
	for (int i = 0; i < tmp.size(); i++)
		for (int j = i + 1; j < tmp.size()&& tmp[j].y - tmp[i].y < d; j++) {
			if (tmp[j].y - tmp[i].y > d) break;
			d = min(d, length(tmp[j] - tmp[i]));
		}
	return d;
}

int main()
{
	while (scanf("%d", &n) == 1 && n) {
		all.clear();
		double x, y;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &x, &y);
			all.push_back(point(x, y));
		}
		sort(all.begin(), all.end());
		printf("%.2f\n", nearest_dist(0, n - 1) / 2);
	}
	return 0;
}
