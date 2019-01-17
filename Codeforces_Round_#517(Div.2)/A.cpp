//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 04:10:41 PM CST
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

int n, m, k;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += (n - 4 * (i - 1)) * (m - 4 * (i - 1));
        ans -= (n - 4 * (i - 1) - 2) * (m - 4 * (i - 1) - 2);
    }
    printf("%d\n", ans);
	return 0;
}
