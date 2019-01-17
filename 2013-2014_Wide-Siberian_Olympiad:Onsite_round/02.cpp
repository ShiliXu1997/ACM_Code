//******************************************************************************
// File Name: 02.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 28 Oct 2018 12:23:02 PM CST
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

int n, root;
vector<int> g[MAXN];
bool done[MAXN];
int ans[MAXN], deg[MAXN];

void dfs(int u, int k)
{
    done[u] = true;
    ans[u] = k;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (done[v]) continue;
        if (k == 1) dfs(v, 2);
        if (k == 2) dfs(v, 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &root);
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        while (x--) {
            int v;
            scanf("%d", &v);
            g[i].push_back(v);
            deg[i]++;
        }
    }
    memset(done, false, sizeof(done));
    memset(ans, 0, sizeof(ans));
    dfs(root, 1);
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= 1) {
            if (ans[i] == 0) printf("-\n");
            if (ans[i] == 1) printf("CW\n");
            if (ans[i] == 2) printf("CCW\n");
        }
    }
	return 0;
}
