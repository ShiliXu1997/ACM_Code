//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 29 Sep 2018 08:57:19 PM CST
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

char s[MAXN];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    bool flag = true;
    if (s[1] == '0' || s[n] == '1') flag = false;
    for (int i = 1; i <= n - 1 && flag; i++)
        if (s[i] != s[n - i]) flag = false;
    if (!flag) {
        printf("-1\n");
        return 0;
    }
    else {
        int now = 2;
        printf("1 2\n");
        for (int i = 2; i < n; i++) {
            if (s[i] == '1') {
                printf("%d %d\n", now, i + 1);
                now = i + 1;
            }
            else {
                printf("%d %d\n", now, i + 1);
            }
        }
    }
	return 0;
}
