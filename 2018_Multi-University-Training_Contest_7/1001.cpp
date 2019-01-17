//******************************************************************************
// File Name: 1001.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月15日 星期三 10时28分59秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5, MAXM = 4e5 + 5, INF = 0x3f3f3f3f;

struct edge {
	int to, color, next;

	edge() {}
	edge(int _to, int _color, int _next) : to(_to), color(_color), next(_next) {}
};

struct node {
	int u, cost;

	node() {}
	node(int _u, int _cost) : u(_u), cost(_cost) {}
};

int n, m, cnt;
edge e[MAXM];
int head[MAXN], dist[MAXN];
bool visited[MAXM];
queue<node> q;

void add_edge(int from, int to, int color)
{
	e[cnt] = edge(to, color, head[from]);
	head[from] = cnt++;
}

void dfs(int u, int c, int d)
{
	dist[u] = min(dist[u], d);
	q.push(node(u, d));
	for (int i = head[u]; i != -1; i = e[i].next) {
		if (visited[i] || e[i].color != c) continue;
		visited[i] = visited[i ^ 1] = true;
		dfs(e[i].to, c, d);
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2) {
		if (m == 0) {
			printf("-1\n");
			continue;
		}
		cnt = 0;
		memset(head, 0xff, sizeof(head));
		for (int i = 1; i <= m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			add_edge(u, v, c);
			add_edge(v, u, c);
		}
		while (!q.empty()) q.pop();
		memset(dist, 0x3f, sizeof(dist));
		memset(visited, false, sizeof(visited));
		dist[0] = 0;
		q.push(node(1, 0));
		while (!q.empty()) {
			node now = q.front(); q.pop();
			for (int i = head[now.u]; i != -1; i = e[i].next) {
				if (visited[i]) continue;
				visited[i] = visited[i ^ 1] = true;
				dfs(e[i].to, e[i].color, now.cost + 1);
			}
			if (dist[n] != INF) break;
		}
		if (dist[n] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[n]);
	}
	return 0;
}
