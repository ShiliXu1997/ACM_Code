#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k, m;
vector<int> v[MAXN];

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        int x, md;
        scanf("%d", &x);
        md = x % m;
        v[md].push_back(x);
    }
    bool flag = false;
    for (int i = 0; i <= m - 1; i++)
        if (v[i].size() >= k) {
            printf("Yes\n");
            for (int j = 0; j < k; j++) printf("%d ", v[i][j]);
            flag = true;
            break;
        }
    if (!flag) printf("No\n");
    return 0;
}
