#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int q, n;

int main()
{
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &n);
        switch (n) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
            printf("-1\n");
            break;
        default:
            int m = n % 4, ans = n / 4;
            if (m == 1) ans--;
            if (m == 3) ans--;
            printf("%d\n", ans);
        }
    }
    return 0;
}
