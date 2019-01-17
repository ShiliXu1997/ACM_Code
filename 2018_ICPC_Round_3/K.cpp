//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月05日 星期三 00时17分54秒
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

struct TestProctoring {
	double expectedTime(vector<int> a, vector<int> b)
	{
		int n = a.size();
		double ans = 0;
		for (int i = 1; i < (1 << n); i++) {
			int sgn = -1;
			double now = 1;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1) now *= (1 - (double)a[j] / b[j]), sgn = -sgn;
			now = 1.0 - now;
			ans += 1.0 * sgn / now;
		}
		return ans;
	}
};
