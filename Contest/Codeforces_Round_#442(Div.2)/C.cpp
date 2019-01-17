#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int ans = n / 2 + n;
    printf("%d\n", ans);
    for (int i = 2; i <= n; i += 2) printf("%d ", i);
    for (int i = 1; i <= n; i += 2) printf("%d ", i);
    for (int i = 2; i <= n; i += 2) printf("%d ", i);
    return 0;
}
