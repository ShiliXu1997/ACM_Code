//******************************************************************************
// File Name: G.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: Wed 17 Oct 2018 12:36:36 PM CST
//******************************************************************************

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;

int t, n, q;
int pre[MAXN];
ll sum[20][MAXN];
int cnt[2][20][MAXN];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        int x;
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            pre[i] = pre[i - 1] ^ x;
        }
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i <= 19; i++) {
            cnt[0][i][0] = 1;
            for (int j = 1; j <= n; j++) {
                sum[i][j] = (sum[i][j - 1] + cnt[(pre[j] >> i & 1) ^ 1][i][j - 1]) % MOD;
                cnt[0][i][j] = cnt[0][i][j - 1];
                cnt[1][i][j] = cnt[1][i][j - 1];
                cnt[pre[j] >> i & 1][i][j]++;
            }
        }
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            ll ans = 0;
            for (int i = 0; i <= 19; i++) {
                ans = (ans + sum[i][r] * (1ll << i)) % MOD;
                ans = ((ans - sum[i][l - 1] * (1ll << i)) % MOD + MOD) % MOD;
                if (l >= 2) {
                    ans = ((ans - (ll)cnt[0][i][l - 2] * (cnt[1][i][r] - cnt[1][i][l - 1]) * (1ll << i)) % MOD + MOD) % MOD;
                    ans = ((ans - (ll)cnt[1][i][l - 2] * (cnt[0][i][r] - cnt[0][i][l - 1]) * (1ll << i)) % MOD + MOD) % MOD;
                }
            }
            printf("%lld\n", ans);
        }
    }
	return 0;
}
