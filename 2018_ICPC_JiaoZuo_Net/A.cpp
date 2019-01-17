//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 15 Sep 2018 12:04:33 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

int t;
string str;

string to_lower(string a)
{
    string ans = "";
    for (int i = 0; i < a.length(); i++) {
        if ('A' <= a[i] && a[i] <= 'Z')
            ans.push_back(a[i] + 32);
        else
            ans.push_back(a[i]);
    }
    return ans;
}

int main()
{
    cin >> t;
    string a = "Good guy!";
    string b = "Dare you say that again?";
    while (t--) {
        cin >> str;
        str = to_lower(str);
        if (str == "jessie")
            cout << a << endl;
        else
            cout << b << endl;
    }
	return 0;
}
