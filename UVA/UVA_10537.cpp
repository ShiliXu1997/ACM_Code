//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月28日 星期三 14时36分25秒
//************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 130;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
	char from, to;

	edge() {}
	edge(char _from, char _to) : from(_from), to(_to) {}
};

struct node {
	char u;
	long long d;

	node() {}
	node(char _u, long long _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int m;
long long num;
char origin, terminal;
long long d[MAXN];
vector<edge> e;
vector<int> g[MAXN];
int last[MAXN];
bool done[MAXN];
priority_queue<node> q;

void add_edge(char from, char to)
{
	e.push_back(edge(from, to));
	g[from].push_back(e.size() - 1);
}

void dijkstra(char x)
{
	memset(done, false, sizeof(done));
	memset(d, 0x3f, sizeof(d));
	d[x] = num;
	q.push(node(x, num));
	while (!q.empty()) {
		char u = q.top().u; q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			long long nxt;
			if ('A' <= u && u <= 'Z')
				nxt = ceil((double)d[u] / 19 * 20);
			else
				nxt = d[u] + 1;
			if (d[now.to] > nxt) {
				d[now.to] = nxt;
				last[now.to] = (int)u;
				q.push(node(now.to, d[now.to]));
			}
			if (d[now.to] == nxt && last[now.to] > (int)u) last[now.to] = (int)u;
		}
	}
}

void init()
{
	e.clear();
	for (char i = 'A'; i <= 'Z'; i++) g[i].clear();
	for (char i = 'a'; i <= 'z'; i++) g[i].clear();
}

int main()
{
	int kase = 0;
	while (scanf("%d", &m) == 1 && m != -1) {
		getchar();
		init();
		char buff[20];
		char from, to;
		stringstream stream;
		for (int i = 1; i <= m; i++) {
			cin.getline(buff, 4);
			stream << buff;
			stream >> from >> to;
			add_edge(from, to);
			add_edge(to, from);
			stream.str(""); stream.clear();
		}
		cin.getline(buff, 20);
		stream << buff;
		stream >> num >> origin >> terminal;
		dijkstra(terminal);
		printf("Case %d:\n", ++kase);
		printf("%lld\n", d[origin]);
		char now = origin;
		while (now != terminal) {
			printf("%c-", now);
			now = last[now];
		}
		printf("%c\n", terminal);
	}
	return 0;
}
