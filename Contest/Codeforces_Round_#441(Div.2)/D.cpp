#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 3e5 + 5;

int n;
bool used[MAXN];

int main()
{
    scanf("%d", &n);
    memset(used, false, sizeof(used));
    printf("1 ");
    int index = n, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        used[x] = true;
        while (used[index]) {
            cnt++;
            index--;
        }
        printf("%d ", i - cnt + 1);
    }
    return 0;
}
