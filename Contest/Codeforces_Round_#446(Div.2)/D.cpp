#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;

int n;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        if (k == n)
            printf("%d ", b[1]);
        else
            printf("%d ", b[k + 1]);
    }
	return 0;
}
