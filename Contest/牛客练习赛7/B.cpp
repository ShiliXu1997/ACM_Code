#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 400;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int t, n, m;
long long dp[MAXN][MAXN], c[MAXN][MAXN], sum[MAXN][MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) sum[i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld", &c[i][j]);
    for (int i = 1; i <= n; i++) sort(c[i] + 1, c[i] + 1 + m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j - 1] + c[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int ed = min(n, (int)m * i);
        for (int j = i; j <= ed; j++) {
            int led = min(n, (int)m * (i - 1));
            for (int k = i - 1; k <= led; k++)
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + sum[i][j - k] + (j - k) * (j - k));
        }
    }
    printf("%lld\n", dp[n][n]);
    return 0;
}
