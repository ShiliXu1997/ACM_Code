//******************************************************************************
// File Name: J.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sun 21 Oct 2018 09:43:38 AM CST
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

string ans[30];

void init()
{
    ans[1] = "a";
    for (int i = 2; i <= 11; i++) ans[i] = ans[i - 1] + (char)('a' + (i - 1)) + ans[i - 1];
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    printf("%c\n", ans[11][n - 1]);
	return 0;
}
