#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2005, INF = 0x3f3f3f3f;

int n;
int a[MAXN];
int d[MAXN][MAXN];

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        d[i][i] = a[i];
        if (a[i] == 1) cnt++;
    }
    if (cnt >= 1)
        printf("%d\n", n - cnt);
    else {
        int res = INF;
        for (int i = n - 1; i >= 1; i--)
            for (int j = i + 1; j <= n; j++) {
                d[i][j] = gcd(d[i][j - 1], a[j]);
                if (d[i][j] == 1) res = min(res, j - i);
            }
        if (res == INF)
            printf("-1\n");
        else
            printf("%d\n", res + n - 1);
    }
    return 0;
}
