#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n;
int a[3] = {1, 2, 3}, pos[4] = {0, 0, 1, 2};

int main()
{
    scanf("%d", &n);
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (pos[x] <= 1) {
            int k = 1 - pos[x];
            swap(a[k], a[2]);
            pos[a[k]] = k;
            pos[a[2]] = 2;
        }
        else
            ans = false;
    }
    if (ans)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
