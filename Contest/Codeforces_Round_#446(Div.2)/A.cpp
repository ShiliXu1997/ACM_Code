#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
long long a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    long long b1 = 0, b2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        if (b1 == 0) {
            b1 = b[i];
            continue;
        }
        if (b2 == 0) {
            b2 = b[i];
            if (b1 < b2) {int t = b1; b1 = b2; b2 = t;}
            continue;
        }
        if (b[i] > b1) {
            b2 = b1;
            b1 = b[i];
            continue;
        }
        if (b[i] > b2) b2 = b[i];
    }
    if (sum <= b1 + b2)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
