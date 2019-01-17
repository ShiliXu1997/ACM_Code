//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 13 Oct 2018 01:31:42 PM CST
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

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        printf("%.5f\n", (double)a / (a + b));
    }
	return 0;
}
