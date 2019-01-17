//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月04日 星期五 15时07分25秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;

struct event {
	int left, right, y, tp, id;

	event() {}
	event(int _left, int _right, int _y, int _tp) : left(_left), right(_right), y(_y), tp(_tp) {}

	bool operator<(const event &another) const
	{
		if (y == another.y) return tp < another.tp;
		return y < another.y;
	}
};

int n, m, cnt;
int a[MAXN], b[MAXN], ans[MAXN];
vector<event> ev;
map<int, int> mp;

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, int num)
{
	while (x <= cnt) {
		b[x] += num;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while (x) {
		ans += b[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ev.push_back(event(x, x, y, 1));
		ev.back().id = i;
		a[++cnt] = x;
	}
	for (int i = 1; i <= m; i++) {
		int x_1, y_1, x_2, y_2;
		scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
		ev.push_back(event(x_1, x_2, y_2, 0));
		ev.push_back(event(x_1, x_2, y_1, 2));
		a[++cnt] = x_1; a[++cnt]= x_2;
	}
	sort(a + 1, a + 1 + cnt);
	cnt = (int)(unique(a + 1, a + 1 + cnt) - (a + 1));
	for (int i = 1; i <= cnt; i++) mp[a[i]] = i;
	sort(ev.begin(), ev.end());
	memset(b, 0, sizeof(b));
	for (auto it = ev.begin(); it != ev.end(); ++it) {
		event now = *it;
		if (now.tp == 0) modify(mp[now.left] + 1, -1), modify(mp[now.right], 1);
		if (now.tp == 1) ans[now.id] = sum(mp[now.left]);
		if (now.tp == 2) modify(mp[now.left] + 1, 1), modify(mp[now.right], -1);
		}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
