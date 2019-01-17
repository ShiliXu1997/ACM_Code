//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 03 Oct 2018 01:40:29 PM CST
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

const int MAXN = 10005;

int n, cnt;
vector<int> g[MAXN];
pair<int, int> fre[MAXN];

void init()
{
    cnt = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
}

void dfs(int u, int fa)
{
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        if (u == 1 && i == 0)
            fre[v] = make_pair(fre[u].first, ++cnt);
        else
            fre[v] = make_pair(fre[u].second, ++cnt);
        dfs(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 2) {
        printf("1 2\n");
        printf("1 2\n");
        return 0;
    }
    fre[1] = make_pair(cnt + 1, cnt + 2);
    cnt += 2;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) printf("%d %d\n", fre[i].first, fre[i].second);
	return 0;
}
