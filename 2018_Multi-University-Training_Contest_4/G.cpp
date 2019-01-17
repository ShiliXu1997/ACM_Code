//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年08月02日 星期四 10时09分36秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

__gnu_pbds::priority_queue<int, less<int>, binomial_heap_tag> p, q;

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int x;
		scanf("%d", &x);
		p.push(x);
	}
	puts("-------");
	for (int i = 1; i <= t; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	p.join(q);
	printf("%d\n", p.top());
	return 0;
}
