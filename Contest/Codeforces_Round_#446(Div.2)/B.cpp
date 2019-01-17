#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

int n;
int l[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
    int t = 0, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (t == 0) ans++;
        if (t >= 1) t--;
        t = max(t, l[i]);
    }
    printf("%d\n", ans);
    return 0;
}
