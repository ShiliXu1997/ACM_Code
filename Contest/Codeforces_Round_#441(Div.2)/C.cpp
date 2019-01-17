#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n;
int num[MAXN];

int main()
{
    scanf("%d", &n);
    int st = max(1, n - 81), cnt = 0;
    for (int i = st; i <= n; i++) {
        int ans = i, temp = i;
        while (temp != 0) {
            ans += temp % 10;
            temp /= 10;
        }
        if (ans == n) num[++cnt] = i;
    }
    printf("%d\n", cnt);
    if (cnt != 0)
        for (int i = 1; i <= cnt; i++) printf("%d ", num[i]);
    return 0;
}
