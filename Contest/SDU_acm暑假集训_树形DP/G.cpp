#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1e5+5,MAXM=1e6+5;

struct edge{
    int to;
    int next;
};

int n,cnt;
int head[MAXN],sz[MAXN];
double expect[MAXN];
bool visited[MAXN];
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
    sz[u]=1;
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        dfs(v);
        sz[u]+=sz[v];
    }
}

void cal(int u)
{
    visited[u]=true;
    for(int i=head[u];i>0;i=e[i].next){
        int v=e[i].to;
        if(visited[v])continue;
        expect[v]=expect[u]+1+(sz[u]-sz[v]-1)*0.5;
        cal(v);
    }
}

int main()
{
    cnt=0;
    memset(head,0,sizeof(head));
    memset(visited,false,sizeof(visited));
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int fa;
        scanf("%d",&fa);
        addedge(fa,i);
    }
    dfs(1);
    memset(visited,false,sizeof(visited));
    expect[1]=1.0;
    cal(1);
    for(int i=1;i<=n;i++)printf("%f ",expect[i]);
    return 0;
}
