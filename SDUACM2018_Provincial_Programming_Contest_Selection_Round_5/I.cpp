//************************************************************************
// File Name: I.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月01日 星期日 19时17分30秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string str;

int main()
{
	while (cin >> str) {
		int len = str.length();
		int ans;
		for (int i = 1; i <= len; i++) 
			if (len % i == 0) {
				string now = str.substr(0, i);
				bool flag = true;
				for (int j = 2; j <= len / i && flag; j++) {
					now = now.substr(i - 1, 1) + now.substr(0, i - 1);
					if (now != str.substr((j - 1) * i, i)) flag = false;
				}
				if (flag) {
					ans = i;
					break;
				}
			}
		cout << ans << endl;
	}
	return 0;
}

