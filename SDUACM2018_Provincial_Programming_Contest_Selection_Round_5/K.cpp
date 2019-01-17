//************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月01日 星期日 20时16分03秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h, w, ha, wa, hb, wb;

int main()
{
	scanf("%d %d", &h, &w);
	scanf("%d %d", &ha, &wa);
	scanf("%d %d", &hb, &wb);
	if (ha > h || wa > w)
		printf("No\nNo");
	else {
		if (h >= hb && (w - wa) >= wb || (h - ha) >= hb && w >= wb)
			printf("Yes\n");
		else
			printf("No\n");
		bool flag = false;
		if ((double)(h - ha) / 2 >= hb && w >= wb) flag = true;
		if (h >= hb && (double)(w - wa) / 2 >= wb) flag = true;
		if (!flag)
			printf("Yes");
		else
			printf("No");
	}
	return 0;
}
