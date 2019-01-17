#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;

int n, m;
int len[MAXN], a[MAXN];
vector<int> ln[MAXN];
vector<long long> sum[MAXN];

void merge(int x, int y)
{
    int i = 0, j = 0, k = 0;
    while (i < ln[x].size() && j < ln[y].size()) {
        if (ln[x][i] <= ln[y][j] + len[y])
            a[k++] = ln[x][i++];
        else
            a[k++] = ln[y][j++] + len[y];
    }
    while (i < ln[x].size()) a[k++] = ln[x][i++];
    while (j < ln[y].size()) a[k++] = ln[y][j++] + len[y];
    ln[x].clear();
    for (int t = 0; t < k; t++) ln[x].push_back(a[t]);
}

long long binsearch(int pos, int remain)
{
    if (remain <= 0) return 0;
    int left = 0, right = ln[pos].size() - 1;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (ln[pos][mid] <= remain)
            left = mid;
        else
            right = mid - 1;
    }
    int cnt;
    if (ln[pos][right] <= remain)
        cnt = right + 1;
    else
        cnt = left + 1;
    return (long long)remain * cnt - sum[pos][cnt - 1];
}

long long solve(int pos, int remain)
{
    long long ans = 0;
    int last= 0;
    while (pos >= 1 && remain > 0) {
        int lson = pos << 1, rson = pos << 1 | 1;
        ans += remain;
        if (lson <= n && lson != last) ans += binsearch(lson, remain - len[lson]);
        if (rson <= n && rson != last) ans += binsearch(rson, remain - len[rson]);
        remain -= len[pos];
        last = pos;
        pos >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) scanf("%d", &len[i]);
    for (int i = 1; i <= n; i++) ln[i].push_back(0);
    for (int i = n; i >= 2; i--) merge(i >> 1, i);
    for (int i = 1; i <= n; i++) {
        sum[i].push_back(0);
        for (int j = 1; j < ln[i].size(); j++)
            sum[i].push_back(sum[i][j - 1] + (long long)ln[i][j]);
    }
    int origin, happiness;
    while (m--) {
        scanf("%d %d", &origin, &happiness);
        long long ans = solve(origin, happiness);
        printf("%lld\n", ans);
    }
    return 0;
}

