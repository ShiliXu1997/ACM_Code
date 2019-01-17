#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1e6 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct point {
    long long x, y;

    bool operator<(const point &another) const
    {
        if (y == another.y)
            return x < another.x;
        return y < another.y;
    }
};

int n, ord;
long long m;
int a[MAXN];
long long num[MAXN];
point p[MAXN];
map<long long, int> id;

int lowbit(int x)
{
    return (x & -x);
}

void modify(int x, int num)
{
    while (x <= ord) {
        a[x] += num;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp(const point &a, const point &b)
{
    return a.x < b.x;
}

int binsearch_l(int num)
{
    int l = 1, r = ord, ans;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (sum(mid) < num)
            l = mid + 1;
        else
            r = mid;
    }
    if (sum(l) == num)
        ans = l;
    else
    if (sum(r) == num)
        ans = r;
    else
        ans = 0;
    return ans;
}

int binsearch_r(int num)
{
    int l = 1, r = ord, ans;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (sum(ord) - sum(mid - 1) > n / 2)
            l = mid + 1;
        else
            r = mid;
    }
    if (sum(ord) - sum(r - 1) == n / 2)
        ans = r;
    else
    if (sum(ord) - sum(l - 1) == n / 2)
        ans = l;
    else
        ans = 0;
    return ans;
}

int main()
{
    while (scanf("%lld %d", &m, &n) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &p[i].x, &p[i].y);
            p[i].x++; p[i].y++;
        }
        if (n % 2 == 0) {
            sort(p + 1, p + 1 + n, cmp);
            ord = 0; id.clear();
            for (int i = 1; i <= n; i++)
                if (!id.count(p[i].x)) {
                    id[p[i].x] = ++ord;
                    num[ord] = p[i].x;
                }
            sort(p + 1, p + 1 + n);
            int index;
            long long ans = INF;
            memset(a, 0, sizeof(a));
            index = 1;
            while (index <= n) {
                while (index + 1 <= n && p[index].y == p[index + 1].y) {
                    modify(id[p[index].x], 1);
                    index++;
                }
                modify(id[p[index].x], 1);
                if (index < n / 2) {index++; continue;}
                int pos;
                pos = binsearch_l(n / 2);
                if (pos != 0) ans = min(ans, num[pos] * p[index].y);
                pos = binsearch_r(n / 2);
                if (pos != 0) ans = min(ans, (m - num[pos] + 1) * p[index].y);
                index++;
            }
            memset(a, 0, sizeof(a));
            index = n;
            while (index >= 1) {
                while (index - 1 >= 1 && p[index].y == p[index - 1].y) {
                    modify(id[p[index].x], 1);
                    index--;
                }
                modify(id[p[index].x], 1);
                if (n - index + 1 < n / 2) {index--; continue;}
                int pos;
                pos = binsearch_l(n / 2);
                if (pos != 0) ans = min(ans, num[pos] * (m - p[index].y + 1));
                pos = binsearch_r(n / 2);
                if (pos != 0) ans = min(ans, (m - num[pos] + 1) * (m - p[index].y + 1));
                index--;
            }
            if (ans == INF)
                printf("-1\n");
            else
                printf("%lld\n", ans);
        }
        else
            printf("-1\n");
    }
    return 0;
}
