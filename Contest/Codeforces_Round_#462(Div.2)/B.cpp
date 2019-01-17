//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月14日 星期三 20时28分17秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k;

int main()
{
	scanf("%d", &k);
	if (k > 36)
		printf("-1");
	else {
		while (k) {
			if (k >= 2) {
				printf("8");
				k -= 2;
			}
			else {
				printf("4");
				k -= 1;
			}
		}
	}
	return 0;
}

