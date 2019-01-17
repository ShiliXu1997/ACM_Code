//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Mon 29 Oct 2018 12:14:39 AM CST
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

char s[MAXN];
int ans[MAXN];

int main()
{
    scanf("%s", &s);
    int len = strlen(s);
    int f = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = len - 1; i >= 0; i--)
        if (!f && s[i] == 'a' || f && s[i] == 'b') ans[i] = 1, f ^= 1;
	for (int i = 0; i < len; i++) printf("%d ", ans[i]);
    return 0;
}
