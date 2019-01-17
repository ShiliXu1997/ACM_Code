//************************************************************************
// File Name: B.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月04日 星期三 00时10分25秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int n, k, m;
string str[MAXN];
int cost[MAXN], ind[MAXN];
map<string, int> mp;

int main()
{
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		mp[str[i]] = i;
	}
	for (int i = 1; i <= n; i++) cin >> cost[i];
	for (int i = 1; i <= k; i++) {
		int x, mn = INF;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> ind[j];
			mn = min(mn, cost[ind[j]]);
		}
		for (int j = 1; j <= x; j++) cost[ind[j]] = mn;
	}
	string now;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		cin >> now;
		ans += (long long)cost[mp[now]];
	}
	cout << ans;
	return 0;
}
