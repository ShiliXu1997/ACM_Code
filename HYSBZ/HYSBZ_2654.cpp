//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月24日 星期六 13时33分04秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct edge {
	int from, to, cost, color;
	bool operator<(const edge &another) const
	{
		if (cost == another.cost) return color < another.color;
		return cost < another.cost;
	}
};

int n, m, need;
int fa[MAXN];
edge e[MAXN];

int find_father(int x)
{
	return (x == fa[x] ? x : fa[x] = find_father(fa[x]));
}

int kruskal(int add, int &cur)
{
	cur = 0;
	int cnt = 0;
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int p = find_father(e[i].from), q = find_father(e[i].to);
		if (p != q) {
			fa[q] = p;
			cur += e[i].cost;
			if (e[i].color == 0) {
				cnt++;
				cur -= add;
			}
		}
	}
	if (cnt >= need) return true;
	return false;
}

bool check(int x, int &cur)
{
	for (int i = 1; i <= m; i++)
		if (e[i].color == 0) e[i].cost += x;
	if (kruskal(x, cur)) {
		for (int i = 1; i <= m; i++)
			if (e[i].color == 0) e[i].cost -= x;
		return true;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &m, &need);
	for (int i = 1; i <= m; i++) scanf("%d %d %d %d", &e[i].from, &e[i].to, &e[i].cost, &e[i].color);
	int l = -100, r = 100, ans;
	while (l <= r) {
		int mid = (l + r) / 2, cur;
		if (check(mid, cur)) {
			ans = cur;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	printf("%d", ans);
	return 0;
}

