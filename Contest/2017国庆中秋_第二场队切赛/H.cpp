#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 45, MAXM = 2050000;

int t, n, m;
int a[MAXN];
long long dp[2][MAXM];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= (1 << 20); j++)
                dp[i % 2][j] = dp[1 - (i % 2)][j] + dp[1 - (i % 2)][j ^ a[i]];
        }
        long long ans = 0;
        for (int i = m; i <= (1 << 20); i++) ans += dp[n % 2][i];
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
