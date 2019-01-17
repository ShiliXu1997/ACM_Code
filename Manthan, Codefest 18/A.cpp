//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月02日 星期日 22时35分03秒
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

int n;

int main()
{
	cin >> n;
	int cnt = 1;
	while (n > 1) {
		n /= 2;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
