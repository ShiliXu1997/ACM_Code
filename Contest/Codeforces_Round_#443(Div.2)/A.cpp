#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n;
int s[MAXN], d[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &s[i], &d[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int time = 0;
        while (s[i] + time * d[i] <= ans) time++;
        ans = s[i] + time * d[i];
    }
    printf("%d", ans);
    return 0;
}
