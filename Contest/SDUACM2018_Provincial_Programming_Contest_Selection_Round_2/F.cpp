//************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月24日 星期六 22时32分59秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-8, PI = acos(-1);
const int MAXN = 105;

struct point {
	double x, y;
	int id;
	
	point() {}
	point(double _x, double _y, int _id = -1) : x(_x), y(_y), id(_id) {}
	bool operator<(const point &another) const;
};

struct ans {
	double val;
	int id;

	ans() {}
	bool operator<(const ans &another) const
	{
		return id < another.id;
	}
};

int tot, n;
point p[MAXN], s[MAXN], normal[MAXN];
ans an[MAXN];
bool visited[MAXN];

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}

double det(const point &a1, const point &a2, const point &b1, const point &b2)
{
	return ((a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x));
}

double dot(const point &a1, const point &a2, const point &b1, const point &b2)
{
	return ((a2.x - a1.x) * (b2.x - b1.x) + (a2.y - a1.y) * (b2.y - b1.y));
}

double dist(const point &p1, const point &p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

bool point::operator<(const point &another) const
{
	if (sgn(det(p[0], *this, p[0], another)) == 0)
		return dist(p[0], *this) < dist(p[0], another);
	else
		return det(p[0], *this, p[0], another) > 0;
}

void graham()
{
	double min_y = p[0].y, min_x = p[0].x;
	int index = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (p[i].y < min_y || (sgn(p[i].y - min_y) == 0 && p[i].x < min_x)) {
			min_y = p[i].y;
			min_x = p[i].x;
			index = i;
		}
	}
	swap(p[0], p[index]);
	sort(p + 1, p + n);
	s[0] = p[0]; s[1] = p[1];
	tot = 2;
	for (int i = 2; i <= n - 1; i++) {
		while (tot >= 2 && sgn(det(s[tot - 1], p[i], s[tot - 1], s[tot - 2]) < 0)) tot--;
		s[tot++] = p[i];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	graham();
	for (int i = 0; i < tot; i++) {
		if (i == 0) {
			normal[i].y = -(s[i].x - s[tot - 1].x);
			normal[i].x = s[i].y - s[tot - 1].y;
			normal[i].id = s[i].id;
		}
		else {
			normal[i].y = -(s[i].x - s[i - 1].x);
			normal[i].x = s[i].y - s[i - 1].y;
			normal[i].id = s[i].id;
		}
	}
	point zero(0, 0);
	for (int i = 0; i < tot; i++) {
		if (i == tot - 1) {
			an[i].val = acos(dot(zero, normal[i], zero, normal[0]) / dist(zero, normal[i]) / dist(zero, normal[0])) / PI / 2;
			an[i].id = normal[i].id;
		}
		else {
			an[i].val = acos(dot(zero, normal[i], zero, normal[i + 1]) / dist(zero, normal[i]) / dist(zero, normal[i + 1])) / PI / 2;
			an[i].id = normal[i].id;
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < tot; i++) visited[s[i].id] = true;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			an[tot].val = 0.0000000;
			an[tot++].id = i;
		}
	sort(an, an + n);
	for (int i = 0; i < n; i++) printf("%.8f\n", an[i].val);
	return 0;
}
