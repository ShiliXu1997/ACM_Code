#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long PRIME[6] = {2, 3, 5, 7, 11, 13};

struct segment {
    int left, right, mid;
    int sum[6];
};

int n, q, cnt;
int in[MAXN], out[MAXN], value[MAXN], factor[6];
vector<int> connect[MAXN];
map<int, int> id;
segment tree[MAXN << 2];

void dfs(int u)
{
    in[u] = ++cnt;
    id[cnt] = u;
    for (int i = 0; i < connect[u].size(); i++) dfs(connect[u][i]);
    out[u] = cnt;
}

long long qpow(int a, int b)
{
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void build(int left, int right, int root)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].mid = (left + right) >> 1;
    memset(tree[root].sum, 0, 6 * sizeof(int));
    if (left == right) {
        for (int i = 0; i < 6; i++) {
            while (value[id[left]] % PRIME[i] == 0) {
                tree[root].sum[i]++;
                value[id[left]] /= PRIME[i];
            }
        }
    }
    else {
        build(left, tree[root].mid, root << 1);
        build(tree[root].mid + 1, right, root << 1 | 1);
        for (int i = 0; i < 6; i++)
            tree[root].sum[i] = tree[root << 1].sum[i] + tree[root << 1 | 1].sum[i];
    }
}

void modify(int left, int right, int num, int root)
{
    if (left <= tree[root].left && tree[root].right <= right) {
        for (int i = 0; i < 6; i++) {
            while (num % PRIME[i] == 0) {
                tree[root].sum[i]++;
                num /= PRIME[i];
            }
        }
    }
    else {
        if (left <= tree[root].mid)
            modify(left, right, num, root << 1);
        if (right >= tree[root].mid + 1)
            modify(left, right, num, root << 1 | 1);
        for (int i = 0; i < 6; i++)
            tree[root].sum[i] = tree[root << 1].sum[i] + tree[root << 1 | 1].sum[i];
    }
}

void query(int left, int right, int root)
{
    if (left <= tree[root].left && tree[root].right <= right) {
        for (int i = 0; i < 6; i++)
            factor[i] += tree[root].sum[i];
    }
    else {
        if (left <= tree[root].mid) query(left, right, root << 1);
        if (right >= tree[root].mid + 1) query(left, right, root << 1 | 1);
    }
}

int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        connect[u].push_back(v);
    }
    cnt = 0;
    dfs(0);
    for (int i = 0; i <= n - 1; i++) scanf("%lld", &value[i]);
    build(1, n, 1);
    char mes[5];
    int x;
    long long t;
    scanf("%d", &q);
    for (int k = 1; k <= q; k++) {
        scanf("%s %d", mes, &x);
        if (mes[0] == 'S') {
            scanf("%d", &t);
            modify(in[x], in[x], t, 1);
        }
        if (mes[0] == 'R') {
            memset(factor, 0, 6 * sizeof(int));
            query(in[x], out[x], 1);
            long long s = 1, ans = 1;
            for (int i = 0; i < 6; i++) {
                s = s * qpow(PRIME[i], factor[i]) % MOD;
                ans = ans * (factor[i] + 1) % MOD;
            }
            printf("%lld %lld\n", s, ans);
        }
    }
    return 0;
}
