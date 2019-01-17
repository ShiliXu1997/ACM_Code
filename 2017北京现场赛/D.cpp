//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 30 Sep 2018 09:23:45 AM CST
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

const int X[7] = {0, -1, 1, -1, 1, 0, 0}, Y[7] = {0, -1, 0, 0, 1, -1, 1};
const int F[7] = {0, 2, 1, 4, 3, 6, 5};
const int T[18] = {0, 4, 4, 4, 4, 0, 1, 2, 3, 4, 4, 4, 4, 4, 9, 10, 11, 12};

struct chess {
    int first, second, tp;

    chess() {}
    chess(int x, int y, int z) : first(x), second(y), tp(z) {}

    bool operator<(const chess &another) const
    {
        if (first != another.first) return first < another.first;
        return second < another.second;
    }
};

int n;
chess grid[18][18];
int be[18][18];
set<chess> st[7];

bool ok(int i, int j)
{
    if (i == 1) return 5 <= j && j <= 5;
    if (i == 2) return 5 <= j && j <= 6;
    if (i == 3) return 5 <= j && j <= 7;
    if (i == 4) return 5 <= j && j <= 8;
    if (i == 5) return 1 <= j && j <= 13;
    if (i == 6) return 2 <= j && j <= 13;
    if (i == 7) return 3 <= j && j <= 13;
    if (i == 8) return 4 <= j && j <= 13;
    if (i == 9) return 5 <= j && j <= 13;
    if (i == 10) return 5 <= j && j <= 14;
    if (i == 11) return 5 <= j && j <= 15;
    if (i == 12) return 5 <= j && j <= 16;
    if (i == 13) return 5 <= j && j <= 17;
    if (i == 14) return 10 <= j && j <= 13;
    if (i == 15) return 11 <= j && j <= 13;
    if (i == 16) return 12 <= j && j <= 13;
    if (i == 17) return 13 <= j && j <= 13;
    return false;
}

void init()
{
    for (int i = 1; i <= 17; i++)
        for (int j = 1; j <= 17; j++) grid[i][j] = chess(i, j, 0);
    memset(be, 0, sizeof(be));
    for (int i = 5; i <= 5; i++) grid[1][i] = chess(1, i, 1), be[1][i] = 1;
    for (int i = 5; i <= 6; i++) grid[2][i] = chess(2, i, 1), be[2][i] = 1;
    for (int i = 5; i <= 7; i++) grid[3][i] = chess(3, i, 1), be[3][i] = 1;
    for (int i = 5; i <= 8; i++) grid[4][i] = chess(4, i, 1), be[4][i] = 1;
    for (int i = 10; i <= 13; i++) grid[14][i] = chess(14, i, 2), be[14][i] = 2;
    for (int i = 11; i <= 13; i++) grid[15][i] = chess(15, i, 2), be[15][i] = 2;
    for (int i = 12; i <= 13; i++) grid[16][i] = chess(16, i, 2), be[16][i] = 2;
    for (int i = 13; i <= 13; i++) grid[17][i] = chess(17, i, 2), be[17][i] = 2;
    for (int i = 1; i <= 4; i++) grid[5][i] = chess(5, i, 6), be[5][i] = 6;
    for (int i = 2; i <= 4; i++) grid[6][i] = chess(6, i, 6), be[6][i] = 6;
    for (int i = 3; i <= 4; i++) grid[7][i] = chess(7, i, 6), be[7][i] = 6;
    for (int i = 4; i <= 4; i++) grid[8][i] = chess(8, i, 6), be[8][i] = 6;
    for (int i = 10; i <= 13; i++) grid[5][i] = chess(5, i, 4), be[5][i] = 4;
    for (int i = 11; i <= 13; i++) grid[6][i] = chess(6, i, 4), be[6][i] = 4;
    for (int i = 12; i <= 13; i++) grid[7][i] = chess(7, i, 4), be[7][i] = 4;
    for (int i = 13; i <= 13; i++) grid[8][i] = chess(8, i, 4), be[8][i] = 4;
    for (int i = 5; i <= 5; i++) grid[10][i] = chess(10, i, 3), be[10][i] = 3;
    for (int i = 5; i <= 6; i++) grid[11][i] = chess(11, i, 3), be[11][i] = 3;
    for (int i = 5; i <= 7; i++) grid[12][i] = chess(12, i, 3), be[12][i] = 3;
    for (int i = 5; i <= 8; i++) grid[13][i] = chess(13, i, 3), be[13][i] = 3;
    for (int i = 14; i <= 14; i++) grid[10][i] = chess(10, i, 5), be[10][i] = 5;
    for (int i = 14; i <= 15; i++) grid[11][i] = chess(11, i, 5), be[11][i] = 5;
    for (int i = 14; i <= 16; i++) grid[12][i] = chess(12, i, 5), be[12][i] = 5;
    for (int i = 14; i <= 17; i++) grid[13][i] = chess(13, i, 5), be[13][i] = 5;
}

bool fuck(int i, int j, int tp)
{
    int op = F[tp];
    for (int k = 1; k <= 6; k++) {
        if (k == tp || k == op) continue;
        if (be[i][j] == k) return true;
    }
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    char s[3];
    while (scanf("%d", &n) == 1) {
        init();
        for (int i = 0; i <= 6; i++) st[i].clear();
        for (int k = 1; k <= n; k++) {
            int nowx, nowy, curx, cury, resx, resy;
            scanf("%d %d %s", &nowx, &nowy, s);
            nowy += T[nowx];
            resx = nowx; resy = nowy;
            int turn = k % 6;
            if (turn == 0) turn = 6;
            if (grid[nowx][nowy].tp != turn) continue;
            int dir = 0;
            string str(s);
            if (str == "UL") dir = 1;
            if (str == "LL") dir = 2;
            if (str == "UR") dir = 3;
            if (str == "LR") dir = 4;
            if (str == "L") dir = 5;
            if (str == "R") dir = 6;
            for (int i = 1; i <= 16; i++) {
                curx = nowx + i * X[dir];
                cury = nowy + i * Y[dir];
                if (!ok(curx, cury) || fuck(curx, cury, turn)) break;
                if (grid[curx][cury].tp != 0) continue;
                int cnt = 0;
                for (int j = 1; j <= i - 1; j++)
                    if (grid[nowx + j * X[dir]][nowy + j * Y[dir]].tp != 0) cnt++;
                if (cnt == 0 && i == 1) resx = curx, resy = cury;
                if (cnt == 0) continue;
                bool flag = true;
                for (int j = 1; j <= i - 1; j++) {
                    if (grid[nowx + j * X[dir]][nowy + j * Y[dir]].tp != 0 && grid[curx - j * X[dir]][cury - j * Y[dir]].tp == 0) flag = false;
                    if (grid[nowx + j * X[dir]][nowy + j * Y[dir]].tp == 0 && grid[curx - j * X[dir]][cury - j * Y[dir]].tp != 0) flag = false;
                }
                if (flag) resx = curx, resy = cury;
            }
            grid[nowx][nowy] = chess(nowx, nowy, 0);
            grid[resx][resy] = chess(resx, resy, turn);
        }
        for (int i = 1; i <= 17; i++)
            for (int j = 1; j <= 17; j++) {
                if (!ok(i, j) || grid[i][j].tp == 0) continue;
                st[grid[i][j].tp].insert(grid[i][j]);
            }
        for (int i = 1; i <= 6; i++) {
            for (set<chess>::iterator it = st[i].begin(); it != st[i].end(); ++it)
                printf("%d %d ", it->first, it->second - T[it->first]);
            puts("");
        }
    }
	return 0;
}
