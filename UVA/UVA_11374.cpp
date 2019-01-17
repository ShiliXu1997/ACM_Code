//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月27日 星期二 20时55分29秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 505, INF = 0x3f3f3f3f;

struct edge {
	int from, to, dist;

	edge() {}
	edge (int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}
};

struct node {
	int u, d;

	node() {}
	node(int _u, int _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int n, origin, terminal, m, k;
vector<edge> e;
vector<int> g[MAXN];
int d1[MAXN], d2[MAXN], last1[MAXN], last2[MAXN];
bool done[MAXN];
priority_queue<node> q;
int com[MAXN][MAXN];

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

void dijkstra(int x)
{
	memset(done, false, sizeof(done));
	if (x == origin){
		memset(d1, 0x3f, sizeof(d1));
		d1[x] = 0;
	}
	else {
		memset(d2, 0x3f, sizeof(d2));
		d2[x] = 0;
	}
	q.push(node(x, 0));
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (x == origin && d1[now.to] > d1[u] + now.dist) {
				d1[now.to] = d1[u] + now.dist;
				last1[now.to] = g[u][i];	
				q.push(node(now.to, d1[now.to]));
			}
			else
			if (x == terminal && d2[now.to] > d2[u] + now.dist) {
				d2[now.to] = d2[u] + now.dist;
				last2[now.to] = g[u][i];
				q.push(node(now.to, d2[now.to]));
			}
		}
	}
}

void init()
{
	e.clear();
	for (int i = 1; i <= n; i++) g[i].clear();
	memset(com, 0x3f, sizeof(com));
}

int main()
{
	bool flag = false;
	while (scanf("%d %d %d", &n, &origin, &terminal) == 3) {
		if (!flag)
			flag = true;
		else
			printf("\n");
		init();
		scanf("%d", &m);
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c);
			add_edge(b, a, c);
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d %d %d", &a, &b, &c);
			com[a][b] = min(com[a][b], c);
			com[b][a] = com[a][b];
		}
		dijkstra(origin);
		dijkstra(terminal);
		int bg, ed, ans = d1[terminal];
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (com[i][j] == INF) continue;
				if (ans > d1[i] + d2[j] + com[i][j]) {
					ans = d1[i] + d2[j] + com[i][j];
					bg = i;
					ed = j;
				}
				if (ans > d1[j] + d2[i] + com[i][j]) {
					ans = d1[j] + d2[i] + com[i][j];
					bg = j;
					ed = i;
				}
			}
		if (ans == d1[terminal]) {
			int now = origin;
			while (now != terminal) {
				printf("%d ", now);
				now = e[last2[now]].from;
			}
			printf("%d\n", terminal);
			printf("Ticket Not Used\n%d\n", ans);
		}
		else {
			int cnt = 0, now = bg;
			int go[MAXN];
			while (now != origin) {
				go[++cnt] = now;
				now = e[last1[now]].from;
			}
			go[++cnt] = origin;
			for (int i = cnt; i >= 1; i--) printf("%d ", go[i]);
			now = ed;
			while (now != terminal) {
				printf("%d ", now);
				now = e[last2[now]].from;
			}
			printf("%d\n%d\n%d\n", terminal, bg, ans);
		}
	}
	return 0;
}
