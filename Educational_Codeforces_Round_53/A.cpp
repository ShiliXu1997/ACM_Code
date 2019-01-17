//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Thu 25 Oct 2018 10:34:34 PM CST
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
string s;

int main()
{
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << "NO" << endl;
        return 0;
    }
    bool flag = false;
    int pos;
    for (int i = 0; i < s.length() - 1 && !flag; i++)
        if (s[i] != s[i + 1]) flag = true, pos = i;
    if (flag) {
        cout << "YES" << endl;
        cout << s[pos] << s[pos + 1] << endl;
    }
    else
        cout << "NO" << endl;
	return 0;
}
