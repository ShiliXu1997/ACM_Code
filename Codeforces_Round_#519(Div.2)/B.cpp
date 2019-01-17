//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 28 Oct 2018 11:42:50 PM CST
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

const int MAXN = 1005, INF = 0x3f3f3f3f;

int n;
int a[MAXN], x[MAXN];
vector<int> ans;

bool check(int k)
{
    memset(x, 0x3f, sizeof(x));
    bool flag = true;
    for (int i = 1; i <= n && flag; i++) {
        int now = a[i] - a[i - 1];
        if (x[(i - 1) % k] == INF) x[(i - 1) % k] = now;
        if (x[(i - 1) % k] != now) flag = false;
    }
    return flag;
}

int main()
{
    scanf("%d", &n);
    a[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int k = 1; k <= n; k++) if (check(k)) ans.push_back(k);
    printf("%d\n", (int)ans.size());
    for (auto i: ans) printf("%d ", i);
	return 0;
}
