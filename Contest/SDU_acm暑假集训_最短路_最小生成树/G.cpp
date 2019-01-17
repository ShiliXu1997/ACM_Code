#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,INF=0x3f3f3f3f;

int n,t;
int path[MAXN][MAXN];
int dist[MAXN];
bool boolset[MAXN];

void dijkstra(int x)
{
    memset(dist,0x3f,sizeof(dist));
    memset(boolset,false,sizeof(boolset));
    for(int i=1;i<=n;i++)dist[i]=path[x][i];
    dist[x]=0;boolset[x]=true;
    for(int i=1;i<=n-1;i++){
        int mindist=INF,u;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&dist[j]<mindist){
                mindist=dist[j];
                u=j;
            }
        boolset[u]=true;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&path[u][j]!=INF&&dist[j]>dist[u]+path[u][j])
                dist[j]=dist[u]+path[u][j];
    }
}

int main()
{
    memset(path,0x3f,sizeof(path));
    scanf("%d %d",&t,&n);
    while(t--){
        int from,to,length;
        scanf("%d %d %d",&from,&to,&length);
        path[from][to]=min(path[from][to],length);
        path[to][from]=path[from][to];
    }
    dijkstra(1);
    printf("%d",dist[n]);
    return 0;
}
