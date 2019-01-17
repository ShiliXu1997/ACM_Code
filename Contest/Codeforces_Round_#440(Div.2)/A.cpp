#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 15;

int n, m;
bool a[MAXN], b[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    int x;
    memset(a, false, sizeof(a));
    memset(b, false, sizeof(b));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        b[x] = true;
    }
    bool flag = false;
    for (int i = 1; i <= 9 && !flag; i++)
        if (a[i] && b[i]) {
            flag = true;
            printf("%d\n", i);
        }
    if (!flag) {
        int min_a, min_b;
        for (int i = 1; i <= 9; i++)
            if (a[i]) {min_a = i; break;}
        for (int i = 1; i <= 9; i++)
            if (b[i]) {min_b = i; break;}
        if (min_a > min_b) {int t = min_a; min_a = min_b; min_b = t;}
        printf("%d%d\n", min_a, min_b);
    }
    return 0;
}
