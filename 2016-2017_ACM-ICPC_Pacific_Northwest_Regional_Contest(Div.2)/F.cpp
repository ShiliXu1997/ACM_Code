//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 27 Sep 2018 07:23:07 PM CST
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
    char s[10];
    fread(s, 9, 1, stdin);
    int a = s[0] - '0', b = s[4] - '0', c = s[8] - '0';
    if (a + b == c)
        cout << "YES";
    else 
        cout << "NO";
	return 0;
}
