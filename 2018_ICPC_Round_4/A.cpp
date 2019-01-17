//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 15时07分31秒
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

string s;

int main()
{
	cin >> s;
	if (s[0] != '-') {
		string ans = "";
		if (s[0] != '0' && s[0] != '+') ans.push_back(s[0]);
		for (int i = 1; i < (int)s.length(); i++) {
			if (ans.empty() && s[i] == '0') continue;
			ans.push_back(s[i]);
		}
		if (ans.empty())
			cout << "0" << endl;
		else
			cout << ans << endl;
	}
	else {
		if (s.length() <= 2)
			cout << s << endl;
		else
		if (s.length() == 3) {
			int ans = -(s[1] - '0') + (s[2] - '0');
			if (s[2] != '0')
				ans = max(ans, -(s[1] - '0') / (s[2] - '0'));
			else
				ans = max(ans, 0);
			cout << ans << endl;
		}
		else {
			if (s[2] == '0') {
				string ans = "";
				for (int i = 2; i < (int)s.length(); i++) {
					if (ans.empty() && s[i] == '0') continue;
					ans.push_back(s[i]);
				}
				if (ans.empty())
					 cout << "0" << endl;
				else
					cout << ans << endl;
			}
			else {
				string right = s.substr(2);
				if (right.back() >= s[1]) {
					right[right.length() - 1] -= (s[1] - '0');
					cout << right << endl;
				}
				else {
					right[right.length() - 1] = ('0' + (right.back() - '0' + 10) - (s[1] - '0'));
					//cout << "----" << endl;
					int pos = right.length() - 2;
					while (pos >= 0) {
						if (right[pos] > '0') {
							right[pos] -= 1;
							break;
						}
						else
							right[pos] = '9';
						pos--;
					}
					bool flag = false;
					for (int i = 0; i < (int)right.length(); i++) {
						if (right[i] == '0' && !flag) continue;
						flag = true;
						printf("%c", right[i]);
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}
