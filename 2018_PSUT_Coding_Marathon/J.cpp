//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月28日 星期二 13时41分59秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

struct square {
	int x, y;

	square() {}
	square(int _x, int _y) : x(_x), y(_y) {}
};

int r, c;
queue<square> q;
bool grid[2000][2000];
char s[2000];

bool check(int i, int j)
{
	bool left = !grid[2 * i][2 * j - 1] && grid[2 * i][2 * j + 1] && grid[2 * i - 1][2 * j] && grid[2 * i + 1][2 * j];
	bool right = grid[2 * i][2 * j - 1] && !grid[2 * i][2 * j + 1] && grid[2 * i - 1][2 * j] && grid[2 * i + 1][2 * j];
	bool up = grid[2 * i][2 * j - 1] && grid[2 * i][2 * j + 1] && !grid[2 * i - 1][2 * j] && grid[2 * i + 1][2 * j];
	bool down = grid[2 * i][2 * j - 1] && grid[2 * i][2 * j + 1] && grid[2 * i - 1][2 * j] && !grid[2 * i + 1][2 * j];
	return left || right || up || down;
}

bool lack_left(int i, int j)
{
	return !grid[2 * i][2 * j - 1];
}

bool lack_right(int i, int j)
{
	return !grid[2 * i][2 * j + 1];
}

bool lack_up(int i, int j)
{
	return !grid[2 * i - 1][2 * j];
}

bool lack_down(int i, int j)
{
	return !grid[2 * i + 1][2 * j];
}

bool ok(int i, int j)
{
	return grid[2 * i][2 * j - 1] && grid[2 * i][2 * j + 1] && grid[2 * i - 1][2 * j] && grid[2 * i + 1][2 * j];
}

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &r, &c);
	memset(grid, false, sizeof(grid));
	for (int i = 1; i <= 2 * r - 1; i++) {
		scanf("%s", s);
		for (int j = 1; j <= 2 * c - 1; j++)\
			grid[i][j] = (s[j - 1] == '|' || s[j - 1] == '-');
	}
	for (int i = 1; i <= r - 1; i++) {
		for (int j = 1; j <= c - 1; j++) {
			if (check(i, j)) q.push(square(i, j));
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		square u = q.front(); q.pop();
		int i = u.x, j = u.y;
		if (ok(i, j)) continue;
		cnt++;
		if (lack_left(i, j)) {
			grid[2 * i][2 * j - 1] = true;
			if (j >= 2) {
				if (check(i, j - 1)) q.push(square(i, j - 1));
				if (ok(i, j - 1)) cnt++;
			}
		}
		if (lack_right(u.x, u.y)) {
			grid[2 * i][2 * j + 1] = true;
			if (j <= c - 2) {
				if (check(i, j + 1)) q.push(square(i, j + 1));
				if (ok(i, j + 1)) cnt++;
			}
		}
		if (lack_up(u.x, u.y)) {
			grid[2 * i - 1][2 * j] = true;
			if (i >= 2) {
				if (check(i - 1, j)) q.push(square(i - 1, j));
				if (ok(i - 1, j)) cnt++;
			}
		}
		if (lack_down(u.x, u.y)) {
			grid[2 * i + 1][2 * j] = true;
			if (i <= r - 2) {
				if (check(i + 1, j)) q.push(square(i + 1, j));
				if (ok(i + 1, j)) cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
