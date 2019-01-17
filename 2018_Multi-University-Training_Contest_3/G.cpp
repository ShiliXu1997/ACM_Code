//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月02日 星期四 22时21分14秒
//******************************************************************************

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

struct point {
	long long x, y;
	int id;

	point(long long _x = 0, long long _y = 0, int _id = 0) : x(_x), y(_y), id(_id) {}
	
	bool operator<(const point &another) const
	{
		if (x == another.x && y == another.y) return id < another.id;
		return (x < another.x) || (x == another.x && y < another.y);
	}
};

typedef point vec;

vec operator-(point a, point b)
{
	return vec(a.x - b.x, a.y - b.y);
}

long long det(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

int t, n;
vector<point> p, ans;

int main()
{
	scanf("%d", &t);
	while (t--) {
		p.clear(); ans.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			long long x, y;
			scanf("%lld %lld", &x, &y);
			p.push_back(point(x, y, i));
		}
		sort(p.begin(), p.end());
		ans.push_back(p[0]); ans.push_back(p[1]);
		for (int i = 2; i < p.size(); i++) {
			if (ans.back().x == p[i].x && ans.back().y == p[i].y) continue;
			while (ans.size() >= 2 && (det(ans.back() - ans[ans.size() - 2], p[i] - ans[ans.size() - 2]) > 0
			|| (det(ans.back() - ans[ans.size() - 2], p[i] - ans[ans.size() - 2]) == 0 && p[i].id < ans.back().id))) ans.pop_back();
			ans.push_back(p[i]);
		}
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i].id, " \n"[i == (int)ans.size() - 1]);
	}
	return 0;
}
