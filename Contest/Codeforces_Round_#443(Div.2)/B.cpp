#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n;
long long k;
long long a[MAXN], dist[MAXN], premax[MAXN];

int main()
{
    scanf("%d %lld", &n, &k);
    long long maxone = 0;
    premax[0] = 0;
    int index;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        premax[i] = max(premax[i - 1], a[i]);
        if (a[i] > maxone) {
            maxone = a[i];
            index = i;
        }
    }
    if (k >= n)
        printf("%lld", maxone);
    else {
        long long ans = 0;
        for (int i = 1; i <= n - 1; i++)
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i]) {dist[i] = j - i - 1; break;}
        for (int i = 1; i < index; i++) {
            if (dist[i] >= k) {ans = a[i]; break;}
            if (i >= 2 && a[i] > premax[i - 1] && dist[i] + 1 >= k) {ans = a[i]; break;}
        }
        if (ans == 0) ans = maxone;
        printf("%lld", ans);
    }
    return 0;
}
