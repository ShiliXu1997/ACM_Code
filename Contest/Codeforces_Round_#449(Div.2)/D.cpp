#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n, m, c, x;
int a[MAXN];

bool check()
{
    for (int i = 1; i <= n; i++) if (!a[i]) return false;
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &c);
    memset(a, 0, sizeof(a));
    while (m-- && !check()) {
        scanf("%d", &x);
        if (x <= c / 2) {
            for (int i = 1; i <= n; i++)
                if (!a[i] || a[i] > x) {
                    a[i] = x;
                    printf("%d\n", i);
                    break;
                }
        }
        else {
            for (int i = n; i >= 1; i--)
                if (!a[i] || a[i] < x) {
                    a[i] = x;
                    printf("%d\n", i);
                    break;
                }
        }
        fflush(stdout);
    }
    return 0;
}
