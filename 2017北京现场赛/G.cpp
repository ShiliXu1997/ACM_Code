//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 30 Sep 2018 06:47:20 PM CST
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

const int MAXN = 25, INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const int X[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1}, Y[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int sgn(double x)
{
    if (fabs(x) < EPS) return 0;
    return (x > 0 ? 1 : -1);
}

struct point {
    double x, y;

    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    bool operator<(const point &another) const
    {
        return (x < another.x) || (x == another.x && y < another.y);
    }

    bool operator==(const point &another) const
    {
        return sgn(x - another.x) == 0 && sgn(y - another.y) == 0;
    }
};

typedef point vec;

vec operator+(vec a, vec b)
{
    return vec(a.x + b.x, a.y + b.y);
}

vec operator-(point a, point b)
{
    return vec(a.x - b.x, a.y - b.y);
}

double dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}

double det(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}

double length(vec a)
{
    return sqrt(dot(a, a));
}

struct line {
    point s, e;

    line() {}
    line(point _s, point _e) : s(_s), e(_e) {}
};

bool ison_point_seg(point p, line l)
{
    return sgn(det(p - l.s, p - l.e)) == 0 && sgn(dot(p - l.s, p - l.e)) <= 0;
}

bool isinter_seg_seg(line l1, line l2)
{
    return sgn(det(l1.e - l1.s, l2.s - l1.s) * det(l1.e - l1.s, l2.e - l1.s)) < 0
        && sgn(det(l2.e - l2.s, l1.s - l2.s) * det(l2.e - l2.s, l1.e - l2.s)) < 0;
}

struct polygon {
    vector<point> p;
    
    polygon() {}
    polygon(vector<point> v)
    {
        p = v;
    }

    int relation_point(point t)
    {
        int cnt = 0;
        for (int i = 0; i < (int)p.size(); i++) {
            if (ison_point_seg(t, line(p[i], p[(i + 1) % p.size()]))) return 2;
            int k = sgn(det(p[(i + 1) % p.size()] - p[i], t - p[i]));
            int d1 = sgn(p[i].y - t.y), d2 = sgn(p[(i + 1) % p.size()].y - t.y);
            if (k > 0 && d1 <= 0 && d2 > 0) cnt++;
            if (k < 0 && d2 <= 0 && d1 > 0) cnt--;
        }
        return cnt != 0;
    }
};

struct node {
    int x, y, d;

    node() {}
    node (int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}

    bool operator<(const node &another) const
    {
        return d > another.d;
    }
};

int n;
char grid[MAXN][MAXN];
vector<point> p;
polygon tri;
int dist[MAXN][MAXN];
bool done[MAXN][MAXN];
priority_queue<node> q;

bool cmp(const point &a, const point &b)
{
    double crs = det(a - p[0], b - p[0]);
    if (sgn(crs) == 0)
        return sgn(length(a - p[0]) - length(b - p[0])) < 0;
    return sgn(crs) > 0;
}

void sort_by_angle()
{
    int pos = 0;
    for (int i = 1; i < (int)p.size(); i++)
        if (p[i].y < p[pos].y || (p[i].y == p[pos].y && p[i].x < p[pos].x)) pos = i;
    swap(p[pos], p[0]);
    sort(p.begin(), p.end(), cmp);
}

bool ok(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dijkstra()
{
    memset(done, false, sizeof(done));
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0] = 0;
    q.push(node(0, 0, 0));
    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (done[now.x][now.y]) continue;
        done[now.x][now.y] = true;
        for (int i = 1; i <= 8; i++) {
            int curx = now.x + X[i], cury = now.y + Y[i];
            if (!ok(curx, cury) || grid[curx][cury] == '#' || done[curx][cury]) continue;
            bool flag = true;
            if (tri.relation_point(point((double)now.x + 1e-4 * X[i], (double)now.y + 1e-4 * Y[i])) == 1) flag = false;
            if (tri.relation_point(point((double)curx - 1e-4 * X[i], (double)cury - 1e-4 * Y[i])) == 1) flag = false;
            for (int j = 0; j < (int)tri.p.size() && flag; j++) {
                if (isinter_seg_seg(line(point(now.x, now.y), point(curx, cury)), line(tri.p[j], tri.p[(j + 1) % p.size()])))
                    flag = false;
            }
            if (!flag) continue;
            if (dist[curx][cury] > dist[now.x][now.y] + 1) {
                dist[curx][cury] = dist[now.x][now.y] + 1;
                q.push(node(curx, cury, dist[curx][cury]));
            }
        }
    }
}

int main()
{
    char s[MAXN];
    while (scanf("%d", &n) == 1) {
        p.clear();
        for (int i = 0; i < 3; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            p.push_back(point(x, y));
        }
        sort_by_angle();
        tri = polygon(p);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            for (int j = 0; j < n; j++) grid[j][n - i - 1] = s[j];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.' && tri.relation_point(point(i, j)) == 1) grid[i][j] = '#';
            }
        dijkstra();
        printf("%d\n", dist[n - 1][n - 1] == INF ? -1 : dist[n - 1][n - 1]);
    }
	return 0;
}
