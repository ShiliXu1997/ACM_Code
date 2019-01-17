//******************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 06 Oct 2018 03:25:00 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5;

int n, q;
vector<int> g[MAXN];
int deep[MAXN], be[MAXN];
int up[MAXN][18];

void init()
{
	for (int i = 1; i <= 17; i++)
		for (int j = 0; j < n; j++) {
			if (up[j][i - 1] == -1) {
                up[j][i] = -1;
                continue;
            }
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
}

int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	int diff = deep[u] - deep[v];
	for (int i = 17; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

void dfs(int u, int d)
{
    deep[u] = d;
    be[u] = be[up[u][0]];
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == up[u][0]) continue;
        dfs(v, d + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    memset(up, 0xff, sizeof(up));
    memset(be, 0, sizeof(be));
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        if (v != -1) g[v].push_back(i), up[i][0] = v;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (up[i][0] == -1) {
            be[i] = ++cnt;
            dfs(i, 0);
        }
    }
    init();
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (be[x] == be[y] && lca(x, y) == y)
            printf("Yes\n");
        else
            printf("No\n");
    }
	return 0;
}
