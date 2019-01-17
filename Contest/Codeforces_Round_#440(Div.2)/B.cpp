#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int n, k;
int a[MAXN], prefix[MAXN], suffix[MAXN];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (k == 1) {
        int ans = INF;
        for (int i = 1; i <= n; i++) ans = min(ans, a[i]);
        printf("%d\n", ans);
    }
    else
    if (k == 2) {
        prefix[1] = a[1]; suffix[n] = a[n];
        for (int i = 2; i <= n - 1; i++)
            prefix[i] = min(prefix[i - 1], a[i]);
        for (int i = n - 1; i >= 2; i--)
            suffix[i] = min(suffix[i + 1], a[i]);
        int ans = -INF;
        for (int i = 1; i <= n - 1; i++)
            ans = max(ans, max(prefix[i], suffix[i + 1]));
        printf("%d\n", ans);
    }
    else {
        int ans = -INF;
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i]);
        printf("%d\n", ans);
    }
    return 0;
}
