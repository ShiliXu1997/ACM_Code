#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int fa[MAXN], c[MAXN];
map<int, bool> visited;

int findfather(int x)
{
    return (fa[x] == x ? x : fa[x] = findfather(fa[x]));
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int p = findfather(a), q = findfather(b), mincost = min(c[p], c[q]);
        if(p != q) fa[q] = p;
        c[p] = c[q] = mincost;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = findfather(i);
        if (!visited.count(k)) {ans += c[k]; visited[k] = true;}
    }
    printf("%lld\n", ans);
    return 0;
}

