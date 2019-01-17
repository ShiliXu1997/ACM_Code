//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 23时57分24秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MAXN = 1e5 + 5;
const double EPS = 1e-15;

int n;
int x[MAXN], y[MAXN];
bool visited[MAXN];

int myrand(int l, int r)
{
	return l + rand() % (r - l + 1);
}

bool in_line(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
	return (long long)(x_2 - x_1) * (y_3 - y_1) - (long long)(y_2 - y_1) * (x_3 - x_1) == 0;
}

int main()
{
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
	if (n <= 4) {
		printf("YES");
		return 0;
	}
	bool flag = false;
	int cnt = 0, p, q, mm, gg;
	while (!flag && ++cnt <= 100) {
		memset(visited, false, sizeof(visited));
		p = 0, q = 0;
		while (p == q) p = myrand(1, n), q = myrand(1, n);
		visited[p] = visited[q] = true;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			if (in_line(x[p], y[p], x[q], y[q], x[i], y[i])) visited[i] = true;
		}
		mm = 0, gg = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			if (mm == 0) mm = i;
			else
			if (gg == 0) gg = i;
		}
		visited[mm] = visited[gg] = true;
		bool finished = true;
		for (int i = 1; i <= n && finished; i++) {
			if (visited[i]) continue;
			if (!in_line(x[mm], y[mm], x[gg], y[gg], x[i], y[i])) finished = false;
		}
		if (finished) flag = true;
	}
	if (flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}
