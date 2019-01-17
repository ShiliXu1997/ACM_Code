#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n;
int f[10];

int main()
{
    f[0] = 1;
    for (int i = 1; i <= 9; i++) {
        f[i] = ((2 << i) - 1) * (2 << (i - 1));
    }
    scanf("%d", &n);
    for (int i = 9; i >= 0; i--)
    if (n % f[i] == 0) {
        printf("%d\n", f[i]);
        break;
    }
    return 0;
}
