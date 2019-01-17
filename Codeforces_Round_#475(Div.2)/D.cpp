//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月25日 星期三 20时29分06秒
//************************************************************************

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

int n, root;
int fa[MAXN], deep[MAXN], deg[MAXN];
vector<int> g[MAXN];
vector<int> ans;
priority_queue<pair<int, int> > q;

void dfs(int u, int fa, int depth)
{
	deep[u] = depth;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u, depth + 1);
	}
}

void add_edge(int from, int to)
{
	g[from].push_back(to); deg[from]++;
	g[to].push_back(from); deg[to]++;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= n; i++) {
		cin >> fa[i];
		if (!fa[i])
			root = i;
		else
			add_edge(fa[i], i);
	}
	if (!(n & 1)) {
		cout << "NO" << endl;
		return 0;
	}
	dfs(root, root, 0);
	for (int i = 1; i <= n; i++) {
		if (!(deg[i] & 1)) q.push(make_pair(deep[i], i));
		if (!deg[i]) ans.push_back(i);
	}
	while (!q.empty()) {
		pair<int, int> now = q.top(); q.pop();
		if (deg[now.second] & 1 || !deg[now.second]) continue;
		deg[now.second] = 0; ans.push_back(now.second);
		for (int i = 0; i < g[now.second].size(); i++) {
			int v = g[now.second][i];
			if (!deg[v]) continue;
			deg[v]--;
			if (!deg[v])
				ans.push_back(v);
			else
			if (!(deg[v] & 1))
				q.push(make_pair(deep[v], v));
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}
