#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 50010;

struct strip {
    int l, r, id;

    bool operator<(const strip &another) const
    {
        if (l < r)
            return l < another.l;
        else
            return l > another.l;
    }
};

int h, n, diff;
int ans[MAXN];
bool visited[MAXN];
strip p[MAXN * 2];

int main()
{
    scanf("%d %d", &h, &n);
    scanf("%d %d", &p[1].l, &p[1].r);
    p[1].id = 1;
    p[1 + n].l = h - p[1].r; p[1 + n].r = h - p[1].l; p[1 + n].id = -1;
    diff = p[1].r - p[1].l;
    bool flag = true;
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &p[i].l, &p[i].r);
        p[i].id = i;
        if (p[i].r - p[i].l != diff) flag = false;
        p[i + n].l = h - p[i].r; p[i + n].r = h - p[i].l; p[i + n].id = -i;
    }
    sort(p + 1, p + 1 + n * 2);
    memset(visited, false, sizeof(visited));
    int tag, cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i == 1) {
            tag = p[i].r;
            ans[++cnt] = p[i].id;
            visited[abs(p[i].id)] = true;
            continue;
        }
        if (tag == p[i].l && !visited[abs(p[i].id)]) {
            tag = p[i].r;
            ans[++cnt] = p[i].id;
            visited[abs(p[i].id)] = true;
        }
    }
    if (cnt < n) flag =false;
    if (!flag)
        printf("0");
    else {
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
    }
    return 0;
}
