//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月08日 星期日 00时07分42秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string s;

int main()
{
	cin >> s;
	int cnt = 0, tot = 0, mos = 0;
	int i;
	bool flag = true;
	int change = 0;
	for (int m = 0; m < s.length(); m++)
		if (m != 0 && s[m - 1] != s[m]) change++;
	if (change != 2) flag = false;
	for (i = 0; flag && (i == 0 || i < s.length() && s[i] == s[i - 1]); i++) if (s[i] == 'a') cnt++;
	if (i != cnt || i == s.length()) flag = false;
	int j = i;
	for (; flag && (i == j || i < s.length() && s[i] == s[i - 1]); i++) if (s[i] == 'b') tot++;
	if (i - j != tot || i == s.length()) flag = false;
	int k = i;
	for (; flag && (i == k || i < s.length() && s[i] == s[i - 1]); i++) if (s[i] == 'c') mos++;
	if (i - k != mos || mos != cnt && mos != tot) flag = false;
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
