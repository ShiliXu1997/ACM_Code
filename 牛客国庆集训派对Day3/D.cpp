//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 03 Oct 2018 04:32:21 PM CST
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

const int MAXN = 1005;

int t, n, m;
ll a[MAXN];
int b[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        if (m > n) m = n;
        int cnt = 0;
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld %d", &a[i], &b[i]);
            if (b[i] == 1) cnt++;
            sum += a[i];
        }
        sort(a + 1, a + 1 + n, greater<ll>());
        double fuck = 0;
        for (int i = 1; i <= min(cnt, m); i++) fuck += (double)(a[i]) / 2;
        printf("%.1f\n", sum - fuck);
    }
	return 0;
}
