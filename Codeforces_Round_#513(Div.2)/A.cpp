//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 04 Oct 2018 03:06:12 PM CST
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

int n;

int main()
{
    scanf("%d", &n);
    char s[105];
    scanf("%s", s);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '8')
            a++;
        else
            b++;
    int cnt = 0;
    while (a--) {
        if (b >= 10)
            cnt++, b -= 10;
        else {
            if (a + b >= 10)
                a -= (10 - b), b -= b, cnt++;
            else
                break;
        }
    }
    printf("%d\n", cnt);
	return 0;
}
