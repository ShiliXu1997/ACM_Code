#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=100,INF=0x3f3f3f3f;

int way[MAXN+5][MAXN+5];
bool boolset[MAXN+5];
int pow[MAXN+5],dist[MAXN],dp[MAXN*MAXN+5];
int n,m,powsum;

int min(const int a,const int b)
{
    return (a<b?a:b);
}

void init()
{
    memset(dist,0x3f,sizeof(dist));
    memset(boolset,false,sizeof(boolset));
    memset(way,0x3f,sizeof(way));
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    powsum=0;
}

void dijkstra()
{
    boolset[0]=true;dist[0]=0;
    for(int i=1;i<=n;i++){
        int u,mindist=INF;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&dist[j]<mindist){
                mindist=dist[j];
                u=j;
            }
        boolset[u]=true;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&way[u][j]!=INF)
                dist[j]=min(dist[j],dist[u]+way[u][j]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            int st,ed,ct;
            scanf("%d %d %d",&st,&ed,&ct);
            way[st][ed]=min(way[st][ed],ct);
            way[ed][st]=way[st][ed];
            if(st==0&&ed!=0)dist[ed]=way[st][ed];
            if(st!=0&&ed==0)dist[st]=way[st][ed];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&pow[i]);
            powsum+=pow[i];
        }
        dijkstra();
        for(int i=1;i<=n;i++)
            for(int j=powsum;j>=pow[i];j--)
                dp[j]=min(dp[j],dp[j-pow[i]]+dist[i]);
        int ans=INF;
        for(int i=powsum/2+1;i<=powsum;i++)
            ans=min(ans,dp[i]);
        if(ans==INF)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
