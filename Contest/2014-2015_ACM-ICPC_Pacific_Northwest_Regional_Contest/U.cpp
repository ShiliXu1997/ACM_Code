//************************************************************************
// File Name: U.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月15日 星期日 13时55分31秒
//************************************************************************

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

int t, n;
string ta[MAXN], tb[MAXN];
set<string> a, b;

int main()
{
	cin >> t;
	while (t--) {
		a.clear(); b.clear();
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> ta[i];
		for (int i = 1; i <= n; i++) cin >> tb[i];
		int st = 1;
		for (int i = 1; i <= n; i++) {
			if (ta[i] == tb[i]) {
				if (a.empty() && b.empty()) cout << i - st + 1 << " ", st = i + 1;
				continue;
			}
			set<string>::iterator it_a = a.find(tb[i]), it_b = b.find(ta[i]);
			if (it_a != a.end())
				a.erase(it_a);
			else
				b.insert(tb[i]);
			if (it_b != b.end())
				b.erase(it_b);
			else
				a.insert(ta[i]);
			if (a.empty() && b.empty()) cout << i - st + 1 << " ", st = i + 1;
		}
		cout << endl;
	}
	return 0;
}
