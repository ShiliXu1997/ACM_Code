//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年03月18日 星期日 13时06分38秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[200];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	bool odd = true;
	for (int i = 0; i < len && odd; i++)
		for (int j = i; j < len && odd; j++) {
			bool flag = true;
			for (int k = 1; k <= (j - i + 1) / 2 + 1 && flag; k++) 
				if (s[i + k - 1] != s[j - k + 1]) {
					flag = false;
				}
			if (flag)
				if ((j - i + 1) % 2 == 0) odd = false;
		}
	printf("%s", odd ? "Odd." : "Or not.");
	return 0;
}
