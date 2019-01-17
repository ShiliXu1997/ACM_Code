//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 03 Oct 2018 06:59:07 PM CST
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

const int MAXN = 5e5 + 5;

ll n, m;
int state[MAXN];
vector<int> g[MAXN];
queue<int> q;
ll add[MAXN], in[MAXN];

int main()
{
    memset(add, 0, sizeof(add));
    memset(in, 0, sizeof(in));
    scanf("%lld %lld", &n, &m);
    char s[2];
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%s %d %d", s, &u, &v);
        if (s[0] == 'L')
            state[i] = 0;
        else
            state[i] = 1;
        g[i].push_back(u);
        g[i].push_back(v);
        in[u]++;
        in[v]++;
    }
    for (int i = 1; i <= m; i++) if (in[i] == 0) q.push(i);
    add[1] = n;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        add[g[u][state[u]]] += (add[u] + 1) / 2;
        add[g[u][state[u] ^ 1]] += add[u] / 2;
        in[g[u][0]]--;
        if (in[g[u][0]] == 0 && g[u][0] != 0) q.push(g[u][0]);
        in[g[u][1]]--;
        if (in[g[u][1]] == 0 && g[u][1] != 0) q.push(g[u][1]);
        state[u] ^= (add[u] & 1);
    }
    for (int i = 1; i <= m; i++) printf("%c", "LR"[state[i]]);
	return 0;
}
