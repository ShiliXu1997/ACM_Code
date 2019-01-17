//************************************************************************
// File Name: R.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年04月15日 星期日 17时21分45秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 100;

int t;
char s[MAXN];
ll dp[MAXN][10];

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int len = strlen(s);
		bool flag = true;
		for (int i = 1; i < len; i++) if (s[i] < s[i - 1]) flag = false;
		if (!flag) {
			printf("-1\n");
			continue;
		}
		for (int i = len - 1; i >= 0; i--) {
			if (i == len - 1) {
				for (int j = 0; j <= 9; j++) dp[i][j] = 1;
			}
			else {
				for (int j = 0; j <= 9; j++) {
					dp[i][j] = 0;
					for (int k = j; k <= 9; k++) dp[i][j] += dp[i + 1][k];
				}
			}
		}
		ll ans = 0;
		int st = 0;
		for (int pos = 0; pos < len; pos++) {
			for (int i = st; i < s[pos] - '0'; i++) ans += dp[pos][i];
			st = s[pos] - '0';
		}
		printf("%lld\n", ans);
	}
	return 0;
}
