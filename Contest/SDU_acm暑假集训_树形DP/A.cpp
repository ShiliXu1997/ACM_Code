#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=110,MAXM=205;

struct edge{
    int to;
    int next;
};

int n,m,cnt;
int num[MAXN],head[MAXN];
bool visited[MAXN];
int dp[MAXN][MAXM][2];
edge e[MAXN*2];

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
    for(int i=0;i<=m;i++){
        dp[u][i][0]=num[u];
        dp[u][i][1]=num[u];
    }
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        dfs(v);
        for(int j=m;j>=0;j--)
            for(int k=1;k<=j;k++){
                if(k>=2)dp[u][j][1]=max(dp[u][j][1],dp[u][j-k][1]+dp[v][k-2][1]);
                dp[u][j][0]=max(dp[u][j][0],dp[u][j-k][1]+dp[v][k-1][0]);
                dp[u][j][0]=max(dp[u][j][0],dp[u][j-k][0]+dp[v][k-2][1]);
            }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)==2){
        cnt=0;
        memset(head,0,sizeof(head));
        memset(dp,0,sizeof(head));
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        for(int i=1;i<=n-1;i++){
            int from,to;
            scanf("%d %d",&from,&to);
            addedge(from,to);
            addedge(to,from);
        }
        dfs(1);
        int ans=max(dp[1][m][0],dp[1][m][1]);
        printf("%d\n",ans);
    }
    return 0;
}
