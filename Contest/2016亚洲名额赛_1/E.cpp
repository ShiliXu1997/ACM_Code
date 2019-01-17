#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 2505;

struct node {
    int x, y;
};

int n, cnt;
long long res[MAXN*3];
int xmatch[MAXN], ymatch[MAXN*3];
bool visited[MAXN*3];
node p[MAXN];
map<long long, int> id;
vector<int> connect[MAXN];

long long add(int a, int b)
{
    return (long long)a + b;
}

long long sub(int a, int b)
{
    return (long long)a - b;
}

long long mul(int a, int b)
{
    return (long long )a * b;
}

bool dfs(int u)
{
    for(int i = 0; i < connect[u].size(); i++){
        int j = connect[u][i];
        if (!visited[j]){
            visited[j] = true;
            if(ymatch[j] == -1 || dfs(ymatch[j])) {
                xmatch[u] = j;
                ymatch[j] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    memset(xmatch, 0xff, sizeof(xmatch));
    memset(ymatch, 0xff, sizeof(ymatch));
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) ans++;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    cnt = 0;
    for (int i = 1; i <= n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        p[i].x = a; p[i].y = b;
        long long ans;
        ans = add(a, b);
        if (!id.count(ans)) {id[ans] = ++cnt; res[cnt] = ans;}
        connect[i].push_back(id[ans]);
        ans = sub(a, b);
        if (!id.count(ans)) {id[ans] = ++cnt; res[cnt] = ans;}
        connect[i].push_back(id[ans]);
        ans = mul(a, b);
        if (!id.count(ans)) {id[ans] = ++cnt; res[cnt] = ans;}
        connect[i].push_back(id[ans]);
    }
    if (n != hungary())
        printf("impossible\n");
    else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", p[i].x);
            if ((long long)p[i].x + p[i].y ==res[xmatch[i]])
                printf("+ ");
            else
            if ((long long)p[i].x - p[i].y ==res[xmatch[i]])
                printf("- ");
            else
            if ((long long)p[i].x * p[i].y ==res[xmatch[i]])
                printf("* ");
            printf("%d = %lld\n", p[i].y, res[xmatch[i]]);
        }
    }
}
