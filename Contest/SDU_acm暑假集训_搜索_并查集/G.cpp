#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=2e5+5;

int n;
int a[MAXN],dist[MAXN];

void dfs(const int x)
{
    if(dist[x]+1<dist[a[x]]){
        dist[a[x]]=dist[x]+1;
        dfs(a[x]);
    }
    if(x+1<=n&&dist[x]+1<dist[x+1]){
        dist[x+1]=dist[x]+1;
        dfs(x+1);
    }
    if(x-1>=1&&dist[x]+1<dist[x-1]){
        dist[x-1]=dist[x]+1;
        dfs(x-1);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    dfs(1);
    for(int i=1;i<=n;i++)
        printf("%d ",dist[i]);
    return 0;
}
