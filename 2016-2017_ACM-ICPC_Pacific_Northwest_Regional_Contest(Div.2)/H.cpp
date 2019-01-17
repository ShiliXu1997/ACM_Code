//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 27 Sep 2018 08:45:02 PM CST
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

int n, m;
char grid[55][55];
bool v[55][55];

bool ok(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int i, int j)
{
    v[i][j] = true;
    if (ok(i - 1, j) && !v[i - 1][j] && grid[i - 1][j] == 'L') dfs(i - 1, j);
    if (ok(i + 1, j) && !v[i + 1][j] && grid[i + 1][j] == 'L') dfs(i + 1, j);
    if (ok(i, j - 1) && !v[i][j - 1] && grid[i][j - 1] == 'L') dfs(i, j - 1);
    if (ok(i, j + 1) && !v[i][j + 1] && grid[i][j + 1] == 'L') dfs(i, j + 1);
}

void fuck(int i, int j)
{
    v[i][j] = true;
    if (grid[i][j] == 'C') grid[i][j] = 'L';
    if (ok(i - 1, j) && !v[i - 1][j] && (grid[i - 1][j] == 'L' || grid[i - 1][j] == 'C')) fuck(i - 1, j);
    if (ok(i + 1, j) && !v[i + 1][j] && (grid[i + 1][j] == 'L' || grid[i + 1][j] == 'C')) fuck(i + 1, j);
    if (ok(i, j - 1) && !v[i][j - 1] && (grid[i][j - 1] == 'L' || grid[i][j - 1] == 'C')) fuck(i, j - 1);
    if (ok(i, j + 1) && !v[i][j + 1] && (grid[i][j + 1] == 'L' || grid[i][j + 1] == 'C')) fuck(i, j + 1);
}


int main()
{
    scanf("%d %d", &n, &m);
    char s[100];
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) grid[i][j] = s[j - 1];
    }
    memset(v, false, sizeof(v));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (!v[i][j] && grid[i][j] == 'L') fuck(i, j);
    }
    memset(v, false, sizeof(v));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (grid[i][j] == 'L' && !v[i][j]) cnt++, dfs(i, j);
    printf("%d\n", cnt);
	return 0;
}
