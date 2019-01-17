//******************************************************************************
// File Name: L.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 12:52:38 PM CST
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
        printf("%d %d\n", (n + 1) >> 1, n >> 1);
    }
	return 0;
}
