//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 01:00:30 PM CST
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

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ll now = 0, x;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x), now ^= x;
        printf("%d\n", now == 0 ? 1 : 0);
    }
	return 0;
}
