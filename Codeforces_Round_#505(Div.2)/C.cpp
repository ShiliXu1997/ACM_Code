//******************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月19日 星期日 23时41分43秒
//******************************************************************************

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

string s;

int main()
{
	cin >> s;
	int n = s.length(), ans = 0;
	s += s;
	for (int i = 0, r; i < 2 * n; i = r + 1) {
		r = i;
		while (r + 1 < 2 * n && r + 2 - i <= n && s[r + 1] != s[r]) r++;
		ans = max(ans, r + 1 - i);
	}
	cout << ans << endl;
	return 0;
}
