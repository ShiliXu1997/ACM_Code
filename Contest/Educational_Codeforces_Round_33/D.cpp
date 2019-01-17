#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n, d;

int main()
{
    scanf("%d %d", &n, &d);
    int x, mn = 0, mx = 0, ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x == 0) {
            if (mx < 0) {
                ans++;
                mx = d; mn = 0;
            }
            else
                mn = max(mn, 0);
        }
        else {
            mx += x; mn += x;
            mx = min(mx, d);
            if (mn > d) flag = false;
        }
    }
    if (!flag) ans = -1;
    printf("%d\n", ans);
    return 0;
}

