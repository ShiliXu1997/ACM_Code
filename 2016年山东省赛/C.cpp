//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月03日 星期四 15时53分08秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 1005, INF = 0x3f3f3f3f;

struct node {
	int u, d;
	node() {}
	node(int _u, int _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int t, n, m;
int cost[MAXN][MAXN];
int d[MAXN];
bool done[MAXN];
priority_queue<node> q;

void init()
{
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = INF;
}

void dijkstra(int x)
{
	memset(d, 0x3f, sizeof(d));
	memset(done, false, sizeof(done));
	d[x] = 0;
	q.push(node(x, 0));
	while (!q.empty()) {
		node now = q.top(); q.pop();
		if (done[now.u]) continue;
		done[now.u] = true;
		for (int i = 0; i <= n + 1; i++)
			if (!done[i] && cost[now.u][i] != INF && cost[now.u][i] + now.d < d[i]) {
				d[i] = cost[now.u][i] + now.d;
				q.push(node(i, d[i]));
			}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		init();
		while (m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			cost[v][u] = w;
		}
		dijkstra(n + 1);
		if (d[0] == INF) {
			printf("-1\n");
			continue;
		}
		bool flag = false;
		for (int i = 1; i <= n + 1 && !flag; i++)
			if (d[0] == d[i] + cost[i][0]) {
				if (i != n + 1)
					printf("%d\n", i);
				else
					printf("0\n");
				flag = true;
			}
	}
	return 0;
}
