//******************************************************************************
// File Name: K.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Sat 15 Sep 2018 03:16:24 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int t, n, q;
int v[25], c[25];
ll dp[10005];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%d %d", &v[i], &c[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = (1 << c[i]) - 1;
            for (int j = 1; j <= num; j <<= 1) {
                int vosum = j * v[i];
                for (int k = 10000; k >= vosum; k--)
                    dp[k] = (dp[k] + dp[k - vosum]) % MOD;
                num -= j;
            }
            if (num > 0) {
                int vosum = num * v[i];
                for (int k = 10000; k >= vosum; k--)
                    dp[k] = (dp[k] + dp[k - vosum]) % MOD;
            }
        }
        while (q--) {
            int s;
            scanf("%d", &s);
            printf("%lld\n", dp[s]);
        }
    }
	return 0;
}
