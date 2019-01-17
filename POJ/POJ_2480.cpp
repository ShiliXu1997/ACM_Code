//******************************************************************************
// File Name: POJ_2480.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年07月29日 星期日 09时26分22秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int n;
ll ans;
map<int, int> p;

int phi(int x)
{
	int ans = x;
	for (int i = 2; (ll)i * i <= x; i++) {
		if (x % i == 0) {
			ans /= i, ans *= (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans /= x, ans *= (x - 1);
	return ans;
}

void get_factor(int x)
{
	p.clear();
	for (int i = 2; (ll)i * i <= x; i++) {
		while (x % i == 0) x /= i, (!p.count(i) ? p[i] = 1 : p[i]++);
	}
	if (x > 1) p[x]++;
}

void dfs(map<int, int>::iterator it, int now)
{
	if (it == p.end()) {
		int m = n / now;
		ans += (ll)phi(m) * now;
		return;
	}
	map<int, int>::iterator a = it;
	for (int i = 0; i <= it->second; i++) dfs(++it, now), it = a, now *= it->first;
}

int main()
{
	while (scanf("%d", &n) == 1) {
		get_factor(n);
		ans = 0;
		dfs(p.begin(), 1);
		printf("%lld\n", ans);
	}
	return 0;
}
