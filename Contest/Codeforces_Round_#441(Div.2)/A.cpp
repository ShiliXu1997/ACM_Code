#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, b, c;

int main()
{
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);
    if (n == 1)
        printf("0\n");
    else {
        int ans = 0, lessone, minone;
        lessone = min(a, b);
        minone = min(lessone, c);
        ans = lessone + (n - 2) * minone;
        printf("%d\n", ans);
    }
    return 0;
}
