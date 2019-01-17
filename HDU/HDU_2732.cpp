//******************************************************************************
// File Name: HDU_2732.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月12日 星期四 20时31分19秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 1005, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow;

	edge() {}
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int t, n, rows, len, leap;
vector<edge> e;
vector<int> g[MAXN];
queue<int> q;
int d[MAXN], cur[MAXN];
int step[25][25];
bool lizard[25][25], reach[25][25];

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int f)
{
	e.push_back(edge(u, v, c, f));
	g[u].push_back(e.size() - 1);
}

bool bfs(int s, int t)
{
	while (!q.empty()) q.pop();
	memset(d, 0, sizeof(d));
	d[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] || now.cap - now.flow == 0) continue;
			d[now.to] = d[u] + 1;
			q.push(now.to);
		}
	}
	return (d[t] != 0);
}

int dfs(int u, int t, int f)
{
	if (u == t || f == 0) return f;
	int ans = 0, add;
	for (int &i = cur[u]; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (d[now.to] == d[u] + 1 && (add = dfs(now.to, t, min(f, now.cap - now.flow))) > 0) {
			e[g[u][i]].flow += add;
			e[g[u][i] ^ 1].flow -= add;
			ans += add;
			f -= add;
			if (f == 0) break;
		}
	}
	return ans;
}

int dinic(int s, int t)
{
	int ans = 0;
	while (bfs(s, t)) {
		memset(cur, 0, sizeof(cur));
		ans += dfs(s, t, INF);
	}
	return ans;
}

bool ok(int x, int y)
{
	return (1 <= x && x <= rows && 1 <= y && y <= len);
}

bool get(int i, int j, int k, int l)
{
	return (abs(i - k) + abs(j - l) <= leap);
}

int main()
{
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		printf("Case #%d: ", kase);
		scanf("%d %d", &rows, &leap);
		char str[25];
		int number = 0;
		for (int i = 1; i <= rows; i++) {
			scanf("%s", str);
			len = strlen(str);
			for (int j = 1; j <= len; j++) step[i][j] = str[j - 1] - '0';
		}
		for (int i = 1; i <= rows; i++) {
			scanf("%s", str);
			for (int j = 1; j <= len; j++)
				if (str[j - 1] == '.')
					lizard[i][j] = false;
				else
					lizard[i][j] = true, number++;
		}
		n = len * rows * 2 + 1;
		init();
		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= len; j++)
				reach[i][j] = (get(i, j, 0, j) || get(i, j, rows + 1, j) || get(i, j, i, 0) || get(i, j, i, len + 1));
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= len; j++) {
				if (step[i][j] != 0) {
					add_edge((i - 1) * len + j, rows * len + (i - 1) * len + j, step[i][j], 0);
					add_edge(rows * len + (i - 1) * len + j, (i - 1) * len + j, 0, 0);
				}
				if (lizard[i][j]) {
					add_edge(0, (i - 1) * len + j, 1, 0);
					add_edge((i - 1) * len + j, 0, 0, 0);
				}
				if (reach[i][j] && step[i][j] != 0) {
					add_edge(rows * len + (i - 1) * len + j, n, INF, 0);
					add_edge(n, rows * len + (i - 1) * len + j, 0, 0);
				}
				else {
					for (int k = i - leap; k <= i + leap; k++)
						for (int l = j - leap; l <= j + leap; l++)
							if (ok(k, l) && (k != i || l != j) && step[i][j] && step[k][l] && get(i, j, k, l)) {
								add_edge(rows * len + (i - 1) * len + j, (k - 1) * len + l, INF, 0);
								add_edge((k - 1) * len + l, rows * len + (i - 1) * len + j, 0, 0);
							}
				}
			}
		}
		int ans = number - dinic(0, n);	
		if (ans == 0) printf("no lizard was left behind.\n");
		if (ans == 1) printf("1 lizard was left behind.\n");
		if (ans >= 2) printf("%d lizards were left behind.\n", ans);
	}
	return 0;
}
