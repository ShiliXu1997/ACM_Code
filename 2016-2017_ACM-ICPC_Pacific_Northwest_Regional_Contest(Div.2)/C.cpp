//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 28 Sep 2018 08:26:07 PM CST
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

const int MAXN = 55, INF = 0x3f3f3f3f;
const int DIRX[5] = {0, -1, 1, 0, 0}, DIRY[5] = {0, 0, 0, -1, 1};

struct node {
    int x, y, z, d;

    node() {}
    node(int _x, int _y, int _z, int _d) : x(_x), y(_y), z(_z), d(_d) {}

    bool operator<(const node &another) const
    {
        return d > another.d;
    }
};

int n, m, len;
char grid[MAXN][MAXN];
char s[MAXN];
pair<int, int> st, ed;
int dist[MAXN][MAXN][MAXN];
bool done[MAXN][MAXN][MAXN];
priority_queue<node> q;

bool ok(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m && grid[x][y] == '.');
}

int get_dir(char c)
{
    if (c == 'U') return 1;
    if (c == 'D') return 2;
    if (c == 'L') return 3;
    if (c == 'R') return 4;
    return 0;
}

void dijkstra()
{
    memset(done, false, sizeof(done));
    memset(dist, 0x3f, sizeof(dist));
    dist[st.first][st.second][0] = 0;
    q.push(node(st.first, st.second, 0, 0));
    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (done[now.x][now.y][now.z]) continue;
        done[now.x][now.y][now.z] = true;
        if (now.z < len) {
            int dir = get_dir(s[now.z + 1]);
            if (ok(now.x + DIRX[dir], now.y + DIRY[dir])) {
                if (!done[now.x + DIRX[dir]][now.y + DIRY[dir]][now.z + 1]) {
                    if (dist[now.x + DIRX[dir]][now.y + DIRY[dir]][now.z + 1] > now.d) {
                        dist[now.x + DIRX[dir]][now.y + DIRY[dir]][now.z + 1] = now.d;
                        q.push(node(now.x + DIRX[dir], now.y + DIRY[dir], now.z + 1, now.d));
                    }
                }
            }
            else {
                if (!done[now.x][now.y][now.z + 1]) {
                    if (dist[now.x][now.y][now.z + 1] > now.d) {
                        dist[now.x][now.y][now.z + 1] = now.d;
                        q.push(node(now.x, now.y, now.z + 1, now.d));
                    }
                }
            }
        }
        for (int i = 1; i <= 4; i++) {
            if (ok(now.x + DIRX[i], now.y + DIRY[i])) {
                if (!done[now.x + DIRX[i]][now.y + DIRY[i]][now.z]) {
                    if (dist[now.x + DIRX[i]][now.y + DIRY[i]][now.z] > now.d + 1) {
                        dist[now.x + DIRX[i]][now.y + DIRY[i]][now.z] = now.d + 1;
                        q.push(node(now.x + DIRX[i], now.y + DIRY[i], now.z, now.d + 1));
                    }
                }
            }
        }
        if (!done[now.x][now.y][now.z + 1]) {
            if (dist[now.x][now.y][now.z + 1] > now.d + 1) {
                dist[now.x][now.y][now.z + 1] = now.d + 1;
                q.push(node(now.x, now.y, now.z + 1, now.d + 1));
            }
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            grid[i][j] = s[j];
            if (s[j] == 'R') st = make_pair(i, j), grid[i][j] = '.';
            if (s[j] == 'E') ed = make_pair(i, j), grid[i][j] = '.';
        }
    }
    scanf("%s", s + 1);
    len = strlen(s + 1);
    dijkstra();
    int ans = INF;
    for (int i = 0; i <= len; i++)
        ans = min(ans, dist[ed.first][ed.second][i]);
    printf("%d\n", ans);
    return 0;
}
