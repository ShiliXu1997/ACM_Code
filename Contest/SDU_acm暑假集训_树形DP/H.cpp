#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1010,MOD=1e9+7;

int t,n;
bool dependent[MAXN],visited[MAXN];
int sz[MAXN];
long long dp[MAXN];
long long C[MAXN][MAXN];
vector<int> child[MAXN];

void init()
{
    C[1][0]=C[1][1]=1;
    for(int i=2;i<=1000;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

void dfs(int u)
{
    visited[u]=true;
    sz[u]=1,dp[u]=1;
    for(int i=0;i<child[u].size();i++){
        int v=child[u][i];
        if(visited[v])continue;
        dfs(v);
        sz[u]+=sz[v];
    }
    int sum=1;
    for(int i=0;i<child[u].size();i++){
        int v=child[u][i];
        dp[u]=dp[u]*dp[v]%MOD*C[sz[u]-sum][sz[v]]%MOD;
        sum+=sz[v];
    }
}

int main()
{
    init();
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        for(int i=0;i<=n;i++)child[i].clear();
        memset(dependent,false,sizeof(dependent));
        memset(visited,false,sizeof(visited));
        scanf("%d",&n);
        for(int i=1;i<=n-1;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            child[from].push_back(to);
            dependent[to]=true;
        }
        for(int i=1;i<=n;i++)
            if(!dependent[i])child[0].push_back(i);
        dfs(0);
        printf("Case %d: %lld\n",kase,dp[0]);
    }
    return 0;
}
