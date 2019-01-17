#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;

const int MAXN = 1005, INF =0x3f3f3f3f;
const int DIR[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, k, x1, y1, x2, y2;
char mp[MAXN][MAXN];
int dist[MAXN][MAXN];
bool in[MAXN][MAXN];
queue<pair<int, int> > q;

bool ok(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void bfs()
{
    memset(in, false, sizeof(in));
    pair<int, int> st, u, v;
    st.x = x1; st.y = y1;
    q.push(st);
    in[x1][y1] = true;
    while (!q.empty()) {
        u = q.front(); q.pop();
        in[u.x][u.y] = false;
        for (int d = 0; d <= 3; d++) {
            v = u;
            for (int i = 1; i <= k; i++) {
                v.x += DIR[d][0]; v.y += DIR[d][1];
                if (ok(v.x, v.y) && mp[v.x][v.y] == '.' && dist[v.x][v.y] >= dist[u.x][u.y] + 1) {
                    dist[v.x][v.y] = dist[u.x][u.y] + 1;
                    if (!in[v.x][v.y]) {q.push(v); in[v.x][v.y] = true;}
                }
                else
                    break;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    char buff[MAXN];
    for (int i = 1; i <= n; i++) {
        scanf("%s", buff);
        for (int j = 1; j <= m; j++) mp[i][j] = buff[j - 1];
    }
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    memset(dist, 0x3f, sizeof(dist));
    dist[x1][y1] = 0;
    bfs();
    if (dist[x2][y2] == INF)
        printf("-1");
    else
        printf("%d", dist[x2][y2]);
    return 0;
}
