//************************************************************************
// File Name: main.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年01月26日 星期五 11时20分43秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5, INF = 1e9;

int n, m, cnt;
int prime[MAXN];
bool boolprime[MAXN];

void euler(int x)
{
	memset(boolprime, false, sizeof(boolprime));
	cnt = 0;
	for (int i = 2; i < x; i++) {
		if (!boolprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && (long long)prime[j] * i <= x; j++) {
			boolprime[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	euler(MAXN);
	int sp;
	for (int i = 1; i <= cnt; i++) 
		if (prime[i] >= n - 1) {
			sp = prime[i];
			break;
		}
	printf("%d %d\n", sp, sp);
	for (int i = 1; i <= n - 1; i++) {
		if (i != n - 1)
			printf("%d %d %d\n", i, i + 1, 1);
		else
			printf("%d %d %d\n", i, i + 1, sp - (n - 2));
	}
	int tot = n - 1;
	for (int i = 1; i <= n - 1 && tot != m; i++)
		for (int j = i + 1; j <= n && tot != m; j++) {
			if (i == j - 1)
				continue;
			else
				tot++, printf("%d %d %d\n", i, j, INF);
		}
	return 0;
}

