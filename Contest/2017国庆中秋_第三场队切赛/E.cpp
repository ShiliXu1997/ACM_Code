#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105, MAXM = 55;

int t, n, m;
int a[MAXM][MAXM], dp[MAXN][MAXM];
int note[MAXN];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++) scanf("%d", &note[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; i++) {
            if (note[i] == -1) {
                for (int j = 1; j <= m; j++) {
                    if (note[i - 1] == -1)
                        for (int k = 1; k <= m; k++) dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[k][j]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i - 1][note[i - 1]] + a[note[i - 1]][j]);
                }
            }
            else {
                if(note[i - 1] == -1)
                    for (int k = 1; k <= m; k++) dp[i][note[i]] = max(dp[i][note[i]], dp[i - 1][k] + a[k][note[i]]);
                else
                    dp[i][note[i]] = max(dp[i][note[i]], dp[i - 1][note[i - 1]] + a[note[i - 1]][note[i]]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
