//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 05:44:53 PM CST
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

const int MAXN = 105;

int n, m;
vector<pii> ans[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) ans[i].push_back(make_pair(i, i));
    int now = n;
    while (m--) {
        now++;
        int x, y;
        scanf("%d %d", &x, &y);
        ans[x].push_back(make_pair(x, now));
        ans[y].push_back(make_pair(y, now));
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", (int)ans[i].size());
        for (auto j: ans[i]) printf("%d %d\n", j.x, j.y);
    }
	return 0;
}
