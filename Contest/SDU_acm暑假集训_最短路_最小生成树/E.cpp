#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=100005,INF=0x3f3f3f3f;

int n,m;
int v[MAXN],enter[MAXN],dp[MAXN];
bool visited[MAXN];
vector<int> way[MAXN];

int dfs(int x)
{
    if(visited[x])return dp[x];
    int k=way[x].size();
    if(k==0)return dp[x]=v[x];
    int ans=-INF;
    for(int i=0;i<k;i++)
        ans=max(ans,v[x]+dfs(way[x][i]));
    visited[x]=true;
    return dp[x]=ans;
}

int main()
{
    while(scanf("%d %d",&n,&m)==2){
        memset(enter,0,sizeof(enter));
        memset(dp,-0x3f,sizeof(dp));
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++)way[i].clear();
        for(int i=1;i<=n;i++)scanf("%d",&v[i]);
        while(m--){
            int from,to;
            scanf("%d %d",&from,&to);
            way[from].push_back(to);
            enter[to]++;
        }
        for(int i=1;i<=n;i++)
            if(enter[i]==0)
                dfs(i);
        int ans=-INF;
        for(int i=1;i<=n;i++)
            if(enter[i]==0)ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
