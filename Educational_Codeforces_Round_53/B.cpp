//******************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 10:47:22 PM CST
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

const int MAXN = 2e5 + 5;

int n;
int mp[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        mp[x] = i;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (now < mp[b[i]])
            printf("%d ", mp[b[i]] - now), now = mp[b[i]];
        else
            printf("0 ");
    }
	return 0;
}
