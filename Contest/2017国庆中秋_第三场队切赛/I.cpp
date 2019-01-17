#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1005;

struct point {
    int t, x, y;

    bool operator<(const point &another) const
    {
        return t < another.t;
    }
};

int t, n;
point p[MAXN];

double dist(const point &p1, const point &p2)
{
    return sqrt(((double)(p1.x - p2.x) * (p1.x - p2.x) + (double)(p1.y - p2.y) * (p1.y - p2.y)));
}

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d %d %d", &p[i].t, &p[i].x, &p[i].y);
        sort(p + 1, p + 1 + n);
        double ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = max(ans, dist(p[i], p[i - 1])/(p[i].t - p[i - 1].t));
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
