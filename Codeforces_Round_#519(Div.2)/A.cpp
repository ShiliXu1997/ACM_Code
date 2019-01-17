//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 28 Oct 2018 11:35:17 PM CST
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

const int MAXN = 105;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    int mx = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
        sum += a[i];
    }
    for (int i = mx; i <= 300; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += i - a[j];
        if (cnt > sum) {
            printf("%d\n", i);
            break;
        }
    }
	return 0;
}
