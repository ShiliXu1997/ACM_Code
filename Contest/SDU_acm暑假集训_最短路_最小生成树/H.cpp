#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1005,INF=0x3f3f3f3f;

int n,m,origin,terminal;
int path[MAXN][MAXN],price[MAXN][MAXN];
int dist[MAXN],cost[MAXN];
bool boolset[MAXN];

void dijkstra(int x)
{
    memset(dist,0x3f,sizeof(dist));
    memset(cost,0x3f,sizeof(cost));
    memset(boolset,false,sizeof(boolset));
    for(int i=1;i<=n;i++){
        dist[i]=path[x][i];
        cost[i]=price[x][i];
    }
    dist[x]=0;boolset[x]=true;
    cost[x]=0;
    for(int i=1;i<=n-1;i++){
        int mindist=INF,u;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&dist[j]<mindist){
                mindist=dist[j];
                u=j;
            }
        boolset[u]=true;
        for(int j=1;j<=n;j++)
            if(!boolset[j]&&path[u][j]!=INF){
                if(dist[j]>dist[u]+path[u][j]){
                    dist[j]=dist[u]+path[u][j];
                    cost[j]=cost[u]+price[u][j];
                }
                else
                if(dist[j]==dist[u]+path[u][j])
                    cost[j]=min(cost[j],cost[u]+price[u][j]);
            }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)){
        memset(path,0x3f,sizeof(path));
        memset(price,0x3f,sizeof(price));
        while(m--){
            int from,to,length,tariff;
            scanf("%d %d %d %d",&from,&to,&length,&tariff);
            if(length<path[from][to]){
                path[from][to]=length;
                path[to][from]=length;
                price[from][to]=tariff;
                price[to][from]=tariff;
            }
            else
            if(length==path[from][to]){
                price[from][to]=min(price[from][to],tariff);
                price[to][from]=price[from][to];
            }
        }
        scanf("%d %d",&origin,&terminal);
        dijkstra(origin);
        printf("%d %d\n",dist[terminal],cost[terminal]);
    }
    return 0;
}
