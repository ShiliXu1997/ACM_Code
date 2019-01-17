#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 10005;

struct record {
    int time, pos;

    bool operator<(const record &another) const
    {
        return (time < another.time);
    }
};

int t, n;
record r[MAXN];

int main()
{
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d %d", &r[i].time, &r[i].pos);
        sort(r + 1, r + 1 + n);
        double speed = 0;
        for (int i = 2; i <= n; i++) {
            double now = fabs((double)(r[i].pos - r[i - 1].pos) / (r[i].time - r[i - 1].time));
            speed = max(speed, now);
        }
        printf("Case #%d: %.2f\n", kase, speed);
    }
    return 0;
}
