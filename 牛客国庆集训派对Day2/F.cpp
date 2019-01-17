//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 02 Oct 2018 04:44:15 PM CST
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

int n, d;
ll a[65];

int main()
{
    scanf("%d %d", &n, &d);
    if (n == 0 || d == 0) {
        printf("0\n");
        return 0;
    }
    if (d >= n) d = n - 1;
    a[0] = 0; a[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= d + 1)
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - d - 1] + a[i - 1] + 1;
    }
    ll ans = (1ll << (n - 1)) - 1 - a[n - d - 1];
    printf("%lld\n", ans);
	return 0;
}
