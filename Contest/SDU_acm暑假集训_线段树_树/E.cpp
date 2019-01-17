#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 35005, MAXM = 55;

struct segment {
    int l, r, mid;
    int maxi, mark;
};

int n, k;
int a[MAXN], last[MAXN], visited[MAXN], dp[MAXN];
segment tree[MAXN * 4];

void build(int left, int right, int root)
{
    tree[root].l = left;
    tree[root].r = right;
    tree[root].mid = (left + right) >> 1;
    tree[root].mark = 0;
    if (left == right) {
        tree[root].maxi = dp[left];
        return;
    }
    build(left, tree[root].mid, root << 1);
    build(tree[root].mid + 1, right, root << 1 | 1);
    tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
}

void push_down(int root)
{
    if (tree[root].mark != 0) {
        tree[root << 1].maxi += tree[root].mark;
        tree[root << 1 | 1].maxi += tree[root].mark;
        tree[root << 1].mark += tree[root].mark;
        tree[root << 1 | 1].mark += tree[root].mark;
        tree[root].mark = 0;
    }
}

void modify(int left, int right, int num, int root)
{
    if (left <= tree[root].l && tree[root].r <= right) {
        tree[root].maxi += num;
        tree[root].mark += num;
        return;
    }
    push_down(root);
    if (left <= tree[root].mid) modify(left, right, num, root << 1);
    if (right >= tree[root].mid + 1) modify(left, right, num, root << 1 | 1);
    tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
}

int query(int left, int right, int root)
{
    if (left <= tree[root].l && tree[root].r <= right) return tree[root].maxi;
    push_down(root);
    int ans = 0;
    if (left <= tree[root].mid) ans = max(ans, query(left, right, root << 1));
    if (right >= tree[root].mid + 1) ans = max(ans, query(left, right, root << 1 | 1));
    return ans;
}

int main()
{
    scanf("%d %d", &n, &k);
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        last[i] = visited[a[i]];
        visited[a[i]] = i;
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= k; j++) {
        build(0, n, 1);
        for (int i = j; i <= n; i++) {
            modify(max(last[i], j - 1), i - 1, 1, 1);
            dp[i] = query(0, i - 1, 1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
