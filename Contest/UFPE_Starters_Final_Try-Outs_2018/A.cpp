//******************************************************************************
// File Name: A.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年05月12日 星期六 16时02分24秒
//******************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;

int n;
char s[MAXN], w[15];
ll dp[15][MAXN];

int main()
{
	scanf("%s %s", s, w);
	int slen = strlen(s), wlen = strlen(w);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < slen; i++) if (s[i] == w[0]) dp[0][i] = 1;
	for (int i = 1; i <= wlen; i++) {
		for (int j = 1; j <= slen; j++) {
			dp[i][j] = dp[i][j - 1];
			if (s[j - 1] == w[i - 1]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	printf("%lld\n", dp[wlen][slen]);
	return 0;
}
