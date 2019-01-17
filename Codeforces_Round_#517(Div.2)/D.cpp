//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 02:36:55 PM CST
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
typedef pair<int, int> pii;
#define x first
#define y second
#define push_back insert

const int MAXN = 2001, INF = 0x3f3f3f3f;

int n, k;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
set<pii> q[2];

bool ok(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%s", grid[i] + 1);
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    int m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dp[i][j] += (grid[i][j] != 'a');
            if (dp[i][j] <= k) m = max(m, i + j - 1);
            if (ok(i + 1, j)) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (ok(i, j + 1)) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    if (m) {
        for (int i = 1; i <= m; i++) printf("%c", 'a');
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) if (dp[i][j] <= k && i + j - 1 == m) q[0].push_back(make_pair(i, j));
    }
    else {
        printf("%c", grid[1][1]);
        q[0].push_back(make_pair(1, 1));
        m++;
    }
    int now = 0;
    while (m < 2 * n - 1) {
        m++;
        char w = 'z';
        for (auto i: q[now]) {
            if (ok(i.x + 1, i.y)) w = min(w, grid[i.x + 1][i.y]);
            if (ok(i.x, i.y + 1)) w = min(w, grid[i.x][i.y + 1]);
        }
        for (auto i: q[now]) {
            if (ok(i.x + 1, i.y) && grid[i.x + 1][i.y] == w) q[now ^ 1].push_back(make_pair(i.x + 1, i.y));
            if (ok(i.x, i.y + 1) && grid[i.x][i.y + 1] == w) q[now ^ 1].push_back(make_pair(i.x, i.y + 1));
        }
        q[now].clear();
        now ^= 1;
        printf("%c", w);
    }
	return 0;
}
