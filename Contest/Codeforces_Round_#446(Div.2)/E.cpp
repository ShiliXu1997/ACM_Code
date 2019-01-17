#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 5;

struct edge {
    int from, to, dist;
};

int n, m, q, cnt;
int fa_1[MAXN], fa_2[MAXN], kase[MAXN];
bool wa[MAXN];
edge e[MAXN];
vector<int> gra[MAXN];
vector<pair<int, int> > qr[MAXN];

int findfather_1(int x)
{
    return (fa_1[x] == x ? x : fa_1[x] = findfather_1(fa_1[x]));
}

int findfather_2(int x)
{
    if (kase[x] != cnt) {kase[x] = cnt; fa_2[x] = findfather_1(x);}
    return (x == fa_2[x] ? x : fa_2[x] = findfather_2(fa_2[x]));
}

int main()
{
    scanf("%d %d", &n, &m);
    int a, b, c, mx = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[i].from = a;
        e[i].to = b;
        e[i].dist = c;
        gra[c].push_back(i);
        mx = max(mx, c);
    }
    int k, x;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &x);
            qr[e[x].dist].push_back(make_pair(i, x));
        }
    }
    memset(wa, false, sizeof(wa));
    memset(kase, 0, sizeof(kase));
    for (int i = 1; i <= n; i++) fa_1[i] = i;
    cnt = 0;
    for (int i = 1; i <= mx; i++) {
        sort(qr[i].begin(), qr[i].end());
        for (int j = 0; j < qr[i].size(); j++) {
            if (j == 0 || qr[i][j].first != qr[i][j - 1].first) cnt++;
            int x = findfather_2(e[qr[i][j].second].from);
            int y = findfather_2(e[qr[i][j].second].to);
            if (x == y) wa[qr[i][j].first] = true;
            fa_2[y] = x;
        }
        for (int j = 0; j < gra[i].size(); j++) {
            int x = findfather_1(e[gra[i][j]].from);
            int y = findfather_1(e[gra[i][j]].to);
            fa_1[y] = x;
        }
    }
    for (int i = 1; i <= q; i++)
        printf(!wa[i] ? "YES\n" : "NO\n");
    return 0;
}
