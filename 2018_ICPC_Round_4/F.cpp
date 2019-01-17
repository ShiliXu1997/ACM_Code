//******************************************************************************
// File Name: F.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 12时55分01秒
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

bool is_digit(char x)
{
	return ('0' <= x && x <= '9');
}

int main()
{
	char c;
	bool flag = true;
	string s = "";
	while (scanf("%c", &c) == 1 && flag) {
		if (c == ' ') {
			if (s.empty())
				continue;
			else
				flag = false;
		}
		if (c == '\n') break;
		if (c == '\r') break;
		if (!is_digit(c))
			flag = false;
		else {
			if ((s.empty() && c != '0') || !s.empty()) s += c;
		}
	}
	if (!flag)
		cout << "invalid input" << endl;
	else {
		if (s.empty())
			cout << "0" << endl;
		else
			cout << s << endl;
	}
	return 0;
}
