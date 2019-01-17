//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 07 Oct 2018 12:17:26 PM CST
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

int t, s, d;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &s, &d);
        printf("%s\n", s >= d ? "YES" : "NO");
    }
	return 0;
}
