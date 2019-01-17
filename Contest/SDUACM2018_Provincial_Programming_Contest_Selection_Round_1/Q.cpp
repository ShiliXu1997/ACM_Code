//************************************************************************
// File Name: Q.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月18日 星期日 14时09分09秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	long long mid = (long long)n * (n - 1) / 2;
	if (mid & 1)
		mid = mid / 2 + 1;
	else
		mid = mid / 2;
	long long sum = 0;
	int index, cnt = 0;
	for (int i = n - 1; i >= 1; i--) {
		sum += i;
		cnt++;
		if (sum >= mid) {
			index = cnt;
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}
