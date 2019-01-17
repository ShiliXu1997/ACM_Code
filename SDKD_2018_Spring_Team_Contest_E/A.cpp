//************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月06日 星期五 16时07分16秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 15;

int t, n, m;
bool ac[MAXN];
int penalty[MAXN];

void init()
{
	memset(ac, false, sizeof(ac));
	memset(penalty, 0, sizeof(penalty));
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int pro, time;
			char t[8], res[8];
			scanf("%d %s %s", &pro, t, res);
			pro -= 1000;
			time = ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
			if (res[0] == 'A') {
				if (!ac[pro]) penalty[pro] += time, ac[pro] = true;
			}
			else {
				if (!ac[pro]) penalty[pro] += 20;
			}
		}
		long long cnt = 0, tt = 0;
		for (int i = 1; i <= n; i++)
			if (ac[i]) {
				cnt++;
				tt += penalty[i];
			}
		printf("%lld %lld\n", cnt, tt);
	}
	return 0;
}
