//******************************************************************************
// File Name: 1003.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月26日 星期日 15时41分46秒
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;

int t, p;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &p);
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) printf("%d ", (i + j) % p);
			puts("");
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < p; j++) printf("%d ", (i * j) % p);
			puts("");
		}
	}
	return 0;
}
