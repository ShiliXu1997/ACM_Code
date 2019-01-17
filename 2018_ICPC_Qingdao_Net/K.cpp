//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 16 Sep 2018 04:17:20 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int t, n;
int a[MAXN];

void fuck(int x)
{
    for (int i = 30; i >= 0; i--)
        if ((x >> i) & 1) {
            a[i]++;
            break;
        }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            fuck(x);
        }
        int mx = 0;
        for (int i = 0; i <= 30; i++) mx = max(mx, a[i]);
        printf("%d\n", mx);
    }
	return 0;
}
