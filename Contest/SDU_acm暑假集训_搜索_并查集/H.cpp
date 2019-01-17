#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=205,INF=0x3f3f3f3f;

int n,origin,terminal;
int k[MAXN],dist[MAXN];

bool ok(const int position)
{
    return (1<=position&&position<=n);
}

void dfs(int x)
{
    int pos1=x+k[x],pos2=x-k[x];
    if(ok(pos1)&&dist[x]+1<dist[pos1]){
        dist[pos1]=dist[x]+1;
        dfs(pos1);
    }
    if(ok(pos2)&&dist[x]+1<dist[pos2]){
        dist[pos2]=dist[x]+1;
        dfs(pos2);
    }
}

int main()
{
    while(scanf("%d",&n)==1&&n!=0){
        scanf("%d %d",&origin,&terminal);
        memset(dist,0x3f,sizeof(dist));
        dist[origin]=0;
        for(int i=1;i<=n;i++)scanf("%d",&k[i]);
        dfs(origin);
        printf("%d\n",dist[terminal]!=INF?dist[terminal]:-1);
    }
    return 0;
}
