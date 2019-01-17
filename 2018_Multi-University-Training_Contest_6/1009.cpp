//******************************************************************************
// File Name: 1009.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月08日 星期三 16时33分52秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, n;
int size[MAXN], fa[MAXN], in[MAXN], debate[MAXN];
vector<int> g[MAXN];

void dfs(int u, int root)
{
	fa[u] = root;
	size[u] = 1;
	for (int i = 0; i < (int)g[u].size(); i++) {
		dfs(g[u][i], root);
		size[u] += size[g[u][i]];
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			g[i].clear(), fa[i] = i;
		memset(in, 0, sizeof(in));
		memset(size, 0, sizeof(size));
		int x;
		char s[10];
		for (int i = 1; i <= n; i++) {
			scanf("%d %s", &x, s);
			bool now = (s[0] == 'w' ? false : true);
			if (now)
				g[x].push_back(i), in[i]++;
			else
				debate[i] = x;
		}
		for (int i = 1; i <= n; i++) if (!in[i]) dfs(i, i);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!in[i] && fa[debate[i]] == i) cnt += size[debate[i]];
		printf("0 %d\n", cnt);
	}
	return 0;
}
