#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 2e5 + 5;

struct segment {
    int left, right, mid;
    int sum, num;
    bool mark;
};

int n, q;
int light[MAXN], in[MAXN], out[MAXN];
vector<int> connect[MAXN];
map<int, int> id;
segment tree[MAXN << 2];

void dfs(int u, int &cnt)
{
    in[u] = cnt; id[cnt] = u;
    for (int i = 0; i < connect[u].size(); i++) {
        int v = connect[u][i];
        dfs(v, ++cnt);
    }
    out[u] = cnt;
}

void build(int left, int right, int root)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].mid = (left + right) >> 1;
    tree[root].mark = false;
    if (left == right) {
        tree[root].sum = 1;
        tree[root].num = light[id[left]];
        return;
    }
    build(left, tree[root].mid, root << 1);
    build (tree[root].mid + 1, right, root << 1 | 1);
    tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
    tree[root].num = tree[root << 1].num + tree[root << 1 | 1].num;
}

void push_down(int root)
{
    if (tree[root].mark) {
        tree[root << 1].num = tree[root << 1].sum - tree[root << 1].num;
        tree[root << 1 | 1].num = tree[root << 1 | 1].sum - tree[root << 1 | 1].num;
        tree[root << 1].mark = !tree[root << 1].mark;
        tree[root << 1 | 1].mark = !tree[root << 1 | 1].mark;
        tree[root].mark = false;
    }
}

void modify(int left, int right, int root)
{
    if (left <= tree[root].left && tree[root].right <= right) {
        tree[root].num = tree[root].sum - tree[root].num;
        tree[root].mark = !tree[root].mark;
        return;
    }
    push_down(root);
    if (left <= tree[root].mid) modify(left, right, root << 1);
    if (right >= tree[root].mid + 1) modify(left, right, root << 1 | 1);
    tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
    tree[root].num = tree[root << 1].num + tree[root << 1 | 1].num;
}

int query(int left, int right, int root)
{
    if (left <= tree[root].left && tree[root].right <= right) return tree[root].num;
    push_down(root);
    int ans = 0;
    if (left <= tree[root].mid) ans += query(left, right, root << 1);
    if (right >= tree[root].mid + 1) ans += query(left, right, root << 1 | 1);
    return ans;
}

int main()
{
    scanf("%d", &n);
    int x;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        connect[x].push_back(i);
    }
    int cnt = 1;
    dfs(1, cnt);
    for (int i = 1; i <= n; i++) scanf("%d", &light[i]);
    build(1, n, 1);
    scanf("%d", &q);
    char mes[5];
    while (q--) {
        scanf("%s %d", mes, &x);
        if (mes[0] == 'p')
            modify(in[x], out[x], 1);
        if (mes[0] == 'g') {
            int ans = query(in[x], out[x], 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
