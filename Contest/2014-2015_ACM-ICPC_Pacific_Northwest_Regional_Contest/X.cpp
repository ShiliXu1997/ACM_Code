//************************************************************************
// File Name: X.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月15日 星期日 14时31分05秒
//************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;

const double EPS = 1e-13;

int t;

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		string str;
		cin >> str;
		int p = str.find('.'), len = str.length();
		double x, ee = 1e8;
		if (p < len) {
			if (len - p - 1 == 1) ee = 0.100000;
			if (len - p - 1 == 2) ee = 0.010000;
			if (len - p - 1 == 3) ee = 0.001000;
			if (len - p - 1 == 4) ee = 0.000100;
			if (len - p - 1 == 5) ee = 0.000010;
			if (len - p - 1 == 6) ee = 0.000001;
		}
		stringstream ss(str);
		ss >> x;
		int zz = floor(x);
		if (x >= 1) printf("%d", zz);
		if (fabs(x - zz) < EPS) {
			printf("\"\n");
			continue;
		}
		if (zz) printf(" ");
		double diff = 1;
		int z = 0, m = 1;
		bool flag = false;
		for (int i = 1; (1 << i) <= 128 && !flag; i++) {
			for (int j = 1; j <= (1 << i) - 1 && !flag; j += 2) {
				if (fabs(x - zz - (double)j / (1 << i)) < diff) z = j, m = i, diff = fabs(x - zz - (double)j / (1 << i));
				if (diff < ee - EPS) flag = true;
			}
		}
		m = (1 << m);
		while (z % 2 == 0 && m % 2 == 0) z /= 2, m /= 2;
		printf("%d/%d\"\n", z, m);
	}
	return 0;
}
