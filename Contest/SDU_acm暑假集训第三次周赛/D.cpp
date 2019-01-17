#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,MAXM=5e5+5,INF=0x3f3f3f3f;

struct edge{
    int to;
    int next;
};

int t,n,m,cnt;
int head[MAXN];
int dp[MAXN][2];
bool visited[MAXN];
edge e[MAXM];

void addedge(int from,int to)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}

void dfs(int u)
{
    visited[u]=true;
    dp[u][0]=0;
    dp[u][1]=1;
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        dfs(v);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}

int main()
{
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        cnt=0;
        memset(head,0,sizeof(head));
        memset(visited,false,sizeof(visited));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            addedge(from,to);
            addedge(to,from);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!visited[i]){
                dfs(i);
                ans+=max(dp[i][0],dp[i][1]);
            }
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
