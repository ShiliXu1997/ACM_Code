//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月13日 星期日 19时09分28秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, m, cnt;
int	skill[MAXN], a[MAXN], b[MAXN], c[MAXN];
vector<int> g[MAXN];
map<int, int> mp;

int lowbit(int x)
{
	return (x & -x);
}

void modify(int x, int num)
{
	while (x <= cnt) {
		a[x] += num;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while (x) {
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}

void add_edge(int from, int to)
{
	g[from].push_back(to);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &skill[i]), b[i] = skill[i];
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
		if (skill[u] < skill[v]) c[v]++;
		if (skill[v] < skill[u]) c[u]++;
	}
	sort(b + 1, b + 1 + n);
	cnt = (int)(unique(b + 1, b + 1 + n) - b - 1);
	for (int i = 1; i <= cnt; i++) mp[b[i]] = i;
	for (int i = 1; i <= n; i++) modify(mp[skill[i]], 1);
	for (int i = 1; i <= n; i++) {
		int ans = sum(mp[skill[i]] - 1) - c[i];
		printf("%d ", ans);
	}
	return 0;
}
