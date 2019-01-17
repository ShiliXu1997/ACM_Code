//******************************************************************************
// File Name: H.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Tue 02 Oct 2018 04:02:09 PM CST
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

const int MAXN = 1e5 + 5;

int n, m, k, t;
double cs[MAXN];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= k; i++) cs[i] = (double)(n - i + 1) / (m - i + 1);
        double ans = 0;
        for (int i = 1; i <= k; i++) ans += cs[i];
        printf("Case #%d: %.8f\n", kase, ans);
    }
	return 0;
}
