//************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 05时08分47秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2e6 + 5;

int n, cnt;
int a[MAXN], prime[MAXN];
bool boolprime[MAXN], used[MAXN];

void euler()
{
	memset(boolprime, false, sizeof(boolprime));
	cnt = 0;
	for (int i = 2; i < MAXN; i++) {
		if (!boolprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && (long long)prime[j] * i <= MAXN; j++) {
			boolprime[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

bool ok(int num)
{
	for (int j = 1; j <= cnt && prime[j] <= num; j++) {
		if (num % prime[j] == 0) {
			if (used[prime[j]]) return false;
			while (num % prime[j] == 0) num /= prime[j];
		}
	}
	return true;
}

int main()
{
	euler();
	memset(used, false, sizeof(used));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	bool fly = false;
	int bg = 1;
	for (int i = 1; i <= n; i++) {
		if (!fly) {
			int t = a[i];
			for (int j = 1; j <= cnt && prime[j] <= t && !fly; j++)
				if (t % prime[j] == 0 && used[prime[j]]) fly = true;
			if (!fly) {
				t = a[i];
				for (int j = 1; j <= cnt && prime[j] <= t && !fly; j++)
					if (t % prime[j] == 0) {
						used[prime[j]] = true;
						while (t % prime[j] == 0) t /= prime[j];
					}
			}
			else {
				for (int j = a[i] + 1; j < MAXN * 10; j++)
					if (ok(j)) {
						a[i] = j;
						break;
					}
				t = a[i];
				for (int j = 1; j <= cnt && prime[j] <= t; j++)
					if (t % prime[j] == 0) {
						used[prime[j]] = true;
						while (t % prime[j] == 0) t /= prime[j];
					}
			}
		}
		else {
			for (int j = bg; j <= cnt; j++)
				if (!used[prime[j]]) {
					a[i] = prime[j];
					bg = j + 1;
					used[prime[j]] = true;
					break;
				}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}
