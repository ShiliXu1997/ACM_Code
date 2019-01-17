//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月03日 星期四 17时12分32秒
//******************************************************************************

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int t;
string buff, str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin.get();
	stringstream ss;	
	while (t--) {
		ss.str(""); ss.clear();
		getline(cin, buff);
		ss << buff;
		bool flag = false;
		while (ss >> str) {
			if (flag) cout << " "; else flag = true;
			int len = str.length();
			for (int i = len - 1; i >= 0; i--) cout << str[i];
		}
		cout << endl;
	}
	return 0;
}
