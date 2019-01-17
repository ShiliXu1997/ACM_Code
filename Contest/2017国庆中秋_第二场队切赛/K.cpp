#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

int t, n;
int a[MAXN], num[MAXN];

int lowbit(int x)
{
    return (x & -x);
}

void modify(int x, int num)
{
    while (x <= n) {
        a[x] += num;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
        int ans = 0;
        memset(a, 0, sizeof(a));
        for (int i = n; i >= 1; i--) {
            if (sum(num[i]) >= 1) ans++;
            modify(num[i], 1);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
