//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年04月10日 星期二 23时06分32秒
//************************************************************************

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 50000, INF = 0x3f3f3f3f;

ll n;
ll square[MAXN];
string sqs[MAXN];
int dp[15][15];

string trans(ll x)
{
	string ans = "";
	while (x) {
		ans = (char)((x % 10) + '0') + ans;
		x /= 10;
	}
	return ans;
}

void init()
{
	for (int i = 1; i <= 48000; i++) {
		square[i] = (ll)i * (ll) i;
		sqs[i] = trans(square[i]);
	}
}

int get(string s, string t)
{
	dp[0][0] = dp[1][0] = dp[0][1] = 0;
	int slen = s.length(), tlen = t.length();
	for (int i = 1; i <= slen; i++)
		for (int j = 1; j <= tlen; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	return dp[slen][tlen];
}

int main()
{
	init();
	scanf("%lld", &n);
	string ns = trans(n);
	int ans = INF;
	for (int i = 1; i <= 48000; i++) {
		int lcs = get(ns, sqs[i]);
		if (lcs == sqs[i].length()) ans = min(ans, (int)ns.length() - lcs);
	}
	printf("%d", ans == INF ? -1 : ans);
	return 0;
}
