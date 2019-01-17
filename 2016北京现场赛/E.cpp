//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 02 Oct 2018 01:11:12 PM CST
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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

struct node {
    int x, y, z;

    node() {}
    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int n;
int dist[MAXN][4][3];
queue<node> q;

void bfs(int x, int y, int z)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[x][y][z] = 0;
    q.push(node(x, y, z));
    while (!q.empty()) {
        node now = q.front(); q.pop();
        int xx = now.x, yy = now.y, zz = now.z;
        for (int i = 0; i < 4; i++) {
            int cur = xx, pp, qq, pow = 1;
            for (int j = 1; j <= i; j++) cur /= 10, pow *= 10;
            pp = cur % 10;
            cur /= 10;
            qq = cur % 10;
            cur /= 10;
            cur = cur * 10 + pp;
            cur = cur * 10 + qq;
            cur = cur * pow +  xx % pow;
            if (dist[cur][yy][zz] == INF) {
                dist[cur][yy][zz] = dist[xx][yy][zz] + 1;
                q.push(node(cur, yy, zz));
            }
        }
        if (yy < 3) {
            for (int i = 0; i < 5; i++) {
                int cur = xx, pp, pow = 1;
                for (int j = 1; j <= i; j++) cur /= 10, pow *= 10;
                pp = cur % 10;
                pp = (pp + 1) % 10;
                cur /= 10;
                cur = cur * 10 + pp;
                cur = cur * pow + xx % pow;
                if (dist[cur][yy + 1][zz] == INF) {
                    dist[cur][yy + 1][zz] = dist[xx][yy][zz] + 1;
                    q.push(node(cur, yy + 1, zz));
                }
            }
        }
        if (zz < 2) {
            for (int i = 0; i < 5; i++) {
                int cur = xx, pp, pow = 1;
                for (int j = 1; j <= i; j++) cur /= 10, pow *= 10;
                pp = cur % 10;
                pp = (pp + pp) % 10;
                cur /= 10;
                cur = cur * 10 + pp;
                cur = cur * pow + xx % pow;
                if (dist[cur][yy][zz + 1] == INF) {
                    dist[cur][yy][zz + 1] = dist[xx][yy][zz] + 1;
                    q.push(node(cur, yy, zz + 1));
                }
            }
        }
    }
}

int main()
{
    bfs(12345, 0, 0);
    while (scanf("%d", &n) == 1) {
        int ans = INF;
        for (int i = 0; i <= 3; i++)
            for (int j = 0; j <= 2; j++) ans = min(ans, dist[n][i][j]);
        printf("%d\n", ans == INF ? -1 : ans);
    }
	return 0;
}
