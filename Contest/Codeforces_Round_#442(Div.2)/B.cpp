#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

char s[MAXN];
int dp[MAXN][3];

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            if (s[i] == 'a') dp[i][0] = 1;
            if (s[i] == 'b') dp[i][1] = 1;
            continue;
        }
        dp[i][0] = dp[i - 1][0] + (s[i] == 'a');
        dp[i][1] = max(dp[i - 1][0] + (s[i] == 'b'), dp[i - 1][1] + (s[i] == 'b'));
        dp[i][2] = max(dp[i - 1][1] + (s[i] == 'a'), dp[i - 1][2] + (s[i] == 'a'));
    }
    int ans = max(dp[len - 1][0], max(dp[len - 1][1], dp[len - 1][2]));
    printf("%d", ans);
    return 0;
}
