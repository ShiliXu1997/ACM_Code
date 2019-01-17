//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Fri 05 Oct 2018 01:11:59 PM CST
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

const int MAXN = 1e6 + 6;

int t, n;
int a[MAXN], c[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void modify(int x)
{
    while (x < MAXN) {
        c[x]++;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(c, 0, sizeof(c));
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            if (sum(a[i])) ans++;
            modify(a[i]);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
	return 0;
}
