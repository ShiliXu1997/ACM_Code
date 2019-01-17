#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN], ans[MAXN];

int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
    scanf("%d", &n);
    int d = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (d == 0)
            d = a[i];
        else
            d = gcd(d, a[i]);
    }
    if (d != a[1])
        printf("-1");
    else {
        printf("%d\n", 2 * n - 1);
        for (int i = 1; i <= 2 * n - 1; i++) {
            if (i & 1)
                printf("%d ", a[(i + 1) / 2]);
            else
                printf("%d ", d);
        }
    }
    return 0;
}
