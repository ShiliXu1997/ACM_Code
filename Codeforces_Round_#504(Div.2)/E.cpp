//******************************************************************************
// File Name: E.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月18日 星期六 14时12分14秒
//******************************************************************************

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
string l, r;

int main()
{
	cin >> n;
	int x = 1, y = 1;
	string mes;
	while (x + y < n + 1) {
		cout << "? " << x << " " << y + 1 << " " << n << " " << n << endl;
		cin >> mes;
		if (mes == "YES")
			y++, l.push_back('R');
		else
			x++, l.push_back('D');
	}
	x = n, y = n;
	while (x + y > n + 1) {
		cout << "? " << 1 << " " << 1 << " " << x - 1 << " " << y << endl;
		cin >> mes;
		if (mes == "YES")
			x--, r.push_back('D');
		else
			y--, r.push_back('R');
	}
	reverse(r.begin(), r.end());
	cout << "! " << l + r << endl;
	return 0;
}
