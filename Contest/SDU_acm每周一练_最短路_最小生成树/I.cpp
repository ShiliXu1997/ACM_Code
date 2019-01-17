#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1050,INF=0x3f3f3f3f;

bool boolset[MAXN];
int dist[MAXN];
int path[MAXN][MAXN];
int n,m;

int min(const int a,const int b)
{
    return (a<b?a:b);
}

void dijkstra()
{
    for(int i=1;i<=n;i++)dist[i]=path[1][i];
    memset(boolset,false,sizeof(boolset));
    dist[1]=0;boolset[1]=true;
    for(int i=1;i<=n-1;i++){
        int mindist=INF,u=0;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&dist[j]<mindist){
                mindist=dist[j];
                u=j;
            }
        boolset[u]=true;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&path[u][j]!=INF)
                dist[j]=min(dist[j],dist[u]+path[u][j]);
    }
}

int main()
{
    memset(path,0x3f,sizeof(path));
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        int st,ed,ct;
        scanf("%d %d %d",&st,&ed,&ct);
        path[st][ed]=min(path[st][ed],ct);
        path[ed][st]=path[st][ed];
    }
    dijkstra();
    printf("%d",dist[n]);
    return 0;
}
